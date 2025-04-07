#include <iostream>
#include <array>
#include <vector>

#define MAX_F 52

using namespace std;

int R, C, T, ret = 0;
int field[MAX_F][MAX_F];
vector<array<int, 2>> purifier;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

bool validate(int r, int c) {
    return r > 0 && r <= R && c > 0 && c <= C;
}

void flow() {
    array<int, 2> cur = purifier[0];
    field[cur[0]][cur[1]] = 0;
    int tmp1, tmp2;
    tmp1 = field[cur[0]][C];
    for(int i = C; i > 1; --i)
        field[cur[0]][i] = field[cur[0]][i-1];
    tmp2 = field[1][C];
    for(int i = 1; i < cur[0]; ++i)
        field[i][C] = field[i+1][C];
    field[cur[0]-1][C] = tmp1;
    tmp1 = field[1][1];
    for(int i = 1; i < C; ++i)
        field[1][i] = field[1][i+1];
    field[1][C-1] = tmp2;
    tmp2 = field[cur[0]][cur[1]];
    for(int i = cur[0]; i > 1; --i)
        field[i][1] = field[i-1][1];
    field[2][1] = tmp1;
    field[cur[0]][cur[1]+1] = tmp2;
    field[cur[0]][cur[1]] = -1;

    cur = purifier[1];
    field[cur[0]][cur[1]] = 0;
    tmp1 = field[cur[0]][C];
    for(int i = C; i > 1; --i)
        field[cur[0]][i] = field[cur[0]][i-1];
    tmp2 = field[R][C];
    for(int i = R; i > cur[0]; --i)
        field[i][C] = field[i-1][C];
    field[cur[0]+1][C] = tmp1;

    tmp1 = field[R][1];
    for(int i = 1; i < C; ++i)
        field[R][i] = field[R][i+1];
    field[R][C-1] = tmp2;
    tmp2 = field[cur[0]][cur[1]];
    for(int i = cur[0]; i < R; ++i)
        field[i][1] = field[i+1][1];
    field[R-1][1] = tmp1;
    field[cur[0]][cur[1]+1] = tmp2;
    field[cur[0]][cur[1]] = -1;
}

void spread() {
    int tmp[MAX_F][MAX_F] = {0};
    for(int i = 1; i <= R; ++i) {
        for(int j = 1; j <= C; ++j) {
            if(!field[i][j] || field[i][j] == -1)
                continue;
            for(int dir = 0; dir < 4; ++dir) {
                int nr = i + dr[dir]; int nc = j + dc[dir];
                if(!validate(nr, nc) || field[nr][nc] == -1)
                    continue;
                tmp[nr][nc] += (field[i][j] / 5);
                tmp[i][j] -= (field[i][j] / 5);
            }
        }
    }

    for(int i = 1; i <= R; ++i)
        for(int j = 1; j <= C; ++j)
            field[i][j] += tmp[i][j];
}

void calculateRet() {
    for(array<int, 2> p : purifier)
        field[p[0]][p[1]] = 0;
    for(int i = 1; i <= R; ++i) {
        for(int j = 1; j <= C; ++j) {
            ret += field[i][j];
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C >> T;
    for(int i = 1; i <= R; ++i) {
        for(int j = 1; j <= C; ++j) {
            cin >> field[i][j];
            if(field[i][j] == -1)
                purifier.push_back({i, j});
        }
    }

    while(T--) {
        spread();
        flow();
    }

    calculateRet();
    cout << ret << "\n";

    return 0;
}