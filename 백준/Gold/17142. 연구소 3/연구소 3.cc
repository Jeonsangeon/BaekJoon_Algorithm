#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
#include <cstring>

#define MAX_N 50
#define INF 0x3fffffff

using namespace std;

int N, M, ret = INF;
int field[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
vector<array<int, 2>> virus;
vector<bool> active;
int empty_count;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

bool validate(int r, int c) {return r >= 0 && r < N && c >= 0 && c < N;}

void bfs() {
    int time, filled = 0;
    memset(visited, 0, sizeof(visited));
    queue<array<int, 3>> q;
    for(int i = 0; i < (int)active.size(); ++i) {
        if(active[i]) {
            q.push({virus[i][0], virus[i][1], 0});
            visited[virus[i][0]][virus[i][1]] = true;
        }
    }

    while(!q.empty()) {
        array<int, 3> cur = q.front(); q.pop();
        if(field[cur[0]][cur[1]] == 0) {
            if(cur[2] >= ret)
                return;
            time = cur[2];
        }
        for(int dir = 0; dir < 4; ++dir) {
            int nr = cur[0] + dr[dir];
            int nc = cur[1] + dc[dir];
            if(!validate(nr, nc) || visited[nr][nc] || field[nr][nc] == 1)
                continue;
            visited[nr][nc] = true;
            if(field[nr][nc] == 0)
                ++filled;
            q.push({nr, nc, cur[2]+1});
        }
    }

    if(empty_count == filled)
        ret = time;
}

void dfs(int count, int idx) {
    if(count == M) {
        bfs();
        return;
    }

    for(int i = idx; i < (int)active.size(); ++i) {
        if(active[i])
            continue;
        active[i] = true;
        dfs(count+1, i+1);
        active[i] = false;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cin >> field[i][j];
            if(field[i][j] == 2) {
                virus.push_back({i, j});
                active.push_back({false});
            } else if(field[i][j] == 0) {
                ++empty_count;
            }
        }
    }

    if(empty_count == 0) {
        cout << "0\n";
        return 0;
    }

    dfs(0, 0);

    if(ret == INF)
        cout << -1 << "\n";
    else
        cout << ret << "\n";

    return 0;
}