#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <cstdlib>
#include <cstring>

#define MAX_N 50

using namespace std;

int N, L, R, ret;
int arr[MAX_N][MAX_N];
int check[MAX_N][MAX_N];

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

bool validate(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < N;
}

vector<array<int, 2>> bfs(array<int, 2> loc) {
    vector<array<int, 2>> group;
    queue<array<int, 2>> q;
    q.push(loc);
    check[loc[0]][loc[1]] = true;
    group.push_back(loc);

    while(!q.empty()) {
        array<int, 2> cur = q.front(); q.pop();

        for(int dir = 0; dir < 4; ++dir) {
            array<int, 2> next;
            next[0] = cur[0] + dr[dir]; 
            next[1] = cur[1] + dc[dir];
            if(!validate(next[0], next[1]) || check[next[0]][next[1]])
                continue;
            int population = abs(arr[cur[0]][cur[1]] - arr[next[0]][next[1]]);
            if(population < L || population > R)
                continue;
            q.push(next);
            group.push_back(next);
            check[next[0]][next[1]] = true;
        }
    }

    return group;
}

bool solve() {
    memset(check, 0, sizeof(check));
    bool moved = false;

    vector<array<int, 2>> group;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            if(check[i][j])
                continue;
            vector<array<int, 2>> group = bfs({i, j});
            if(group.size() == 1) continue;

            int total = 0;
            for(array<int, 2> g : group) total += arr[g[0]][g[1]];
            int avg = (total / group.size());
            for(array<int, 2> g : group) arr[g[0]][g[1]] = avg;
            moved = true;
        }
    }

    if(moved)
        ++ret;

    return moved;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> L >> R;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cin >> arr[i][j];
        }
    }

    while(solve());

    cout << ret << "\n";

    return 0;
}