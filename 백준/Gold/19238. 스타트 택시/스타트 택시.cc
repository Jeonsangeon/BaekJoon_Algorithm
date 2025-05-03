#include <iostream>
#include <array>
#include <queue>

#define MAX_N 21
#define MAX_M 402

using namespace std;

int N, M, fuel, ret;
array<int, 2> taxi;
array<int, 4> passenger[MAX_M];
int field[MAX_N][MAX_N];

int dr[] = {-1, 0, 0, 1};
int dc[] = {0, -1, 1, 0};

bool validate(int r ,int c) {
    return r > 0 && r <= N && c > 0 && c <= N;
}

int toDestination(int dest_r, int dest_c) {
    bool visited[MAX_N][MAX_N] = {0, };
    queue<array<int, 3>> q;
    q.push({taxi[0], taxi[1], 0});
    visited[taxi[0]][taxi[1]] = true;

    while(!q.empty()) {
        array<int, 3> cur = q.front(); q.pop();

        if(dest_r == cur[0] && dest_c == cur[1]) {
            taxi = {cur[0], cur[1]};
            return cur[2];
        }
        
        for(int dir = 0; dir < 4; ++dir) {
            int nr = cur[0] + dr[dir];
            int nc = cur[1] + dc[dir];
            if(!validate(nr, nc) || visited[nr][nc])
                continue;
            if(field[nr][nc] == 1)
                continue;
            q.push({nr, nc, cur[2]+1});
            visited[nr][nc] = true;
        }
    }

    return -1;
}

int toPassienger() {
    int min_fuel = 500000;
    bool visited[MAX_N][MAX_N] = {0,};
    queue<array<int, 3>> q;
    q.push({taxi[0], taxi[1], 0});
    visited[taxi[0]][taxi[1]] = true;

    while(!q.empty()) { 
        array<int, 3> cur = q.front(); q.pop();
        if(field[cur[0]][cur[1]] > 1 && cur[2] <= min_fuel) {
            if(min_fuel == 500000) {
                taxi = {cur[0], cur[1]};
                min_fuel = cur[2];
            }
            else {
                if(cur[0] < taxi[0])
                    taxi = {cur[0], cur[1]};
                else if (cur[0] == taxi[0] && cur[1] < taxi[1])
                    taxi = {cur[0], cur[1]};
            }        
        }

        for(int dir = 0; dir < 4; ++dir) {
            int nr = cur[0] + dr[dir];
            int nc = cur[1] + dc[dir];
            if(!validate(nr, nc) || visited[nr][nc])
                continue;
            if(field[nr][nc] == 1 || cur[2] > min_fuel)
                continue;
            q.push({nr, nc, cur[2]+1});
            visited[nr][nc] = true;
        }
    }
    if(min_fuel == 500000)
        return -1;
    return min_fuel;
}

bool drive() {
    int used_fuel = toPassienger();
    fuel -= used_fuel;
    int p_num = field[taxi[0]][taxi[1]];
    field[taxi[0]][taxi[1]] = 0;
    if(fuel < 0 || used_fuel == -1)
        return false;
    used_fuel = toDestination(passenger[p_num][2], passenger[p_num][3]);
    fuel -= used_fuel;
    if(fuel < 0 || used_fuel == -1)
        return false;
    fuel += (2 * used_fuel);
    ++ret;
    return true;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> fuel;
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            cin >> field[i][j];
        }
    }
    cin >> taxi[0] >> taxi[1];
    for(int i = 2; i < M+2; ++i) {
        cin >> passenger[i][0] >> passenger[i][1] >> passenger[i][2] >> passenger[i][3];
        field[passenger[i][0]][passenger[i][1]] = i;
    }

    while(ret < M) {
        if(!drive())
            break;
    }

    if(ret == M)
        cout << fuel << "\n";
    else
        cout << -1 << "\n";

    return 0;
}