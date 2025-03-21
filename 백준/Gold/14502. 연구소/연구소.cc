#include <iostream>
#include <vector>
#include <queue>
#include <array>
#include <cstring>

#define MAX_N 8
#define MAX_M 8

using namespace std;

int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

int N, M, ret = 0;
int map[MAX_N][MAX_M];
vector<array<int, 2>> virus;

int checkArea(int tmp[MAX_N][MAX_M]) {
    int area = 0;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            if(!tmp[i][j])
                ++area;
        }
    }
    return area;
}

void bfs() {
    int tmp[MAX_N][MAX_M];
    memcpy(tmp, map, sizeof(map));
    queue<array<int, 2>> q;
    for(array<int, 2> i : virus)
        q.push(i);
    
    while(!q.empty()) {
        array<int, 2> cur = q.front(); q.pop();

        for(int i = 0; i < 4; ++i) {
            array<int, 2> next = {cur[0] + dr[i] , cur[1] + dc[i]};
            if(next[0] < 0 || next[0] >= N || next[1] < 0 || next[1] >= M)
                continue;
            if(tmp[next[0]][next[1]])
                continue;
            tmp[next[0]][next[1]] = 2;
            q.push(next);
        }
    }

    ret = max(ret, checkArea(tmp));
}

void backtracking(int wall, int loc) {
    if(wall == 3) {
        bfs();
        return;
    }
    while(loc < N * M) {
        int r = loc / M;
        int c = loc % M;
        if(!map[r][c]) {
            map[r][c] = 1;
            backtracking(wall+1, loc+1);
            map[r][c] = 0;
        }
        ++loc;
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            cin >> map[i][j];
            if(map[i][j] == 2)
                virus.push_back({i, j});
        }
    }
    backtracking(0, 0);

    cout << ret << "\n";

    return 0;
}