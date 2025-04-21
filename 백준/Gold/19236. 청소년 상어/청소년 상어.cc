#include <iostream>
#include <algorithm>

#define MAX_N 4
#define MAX_F 17

struct Fish {
    int row;
    int col;
    int dir;
    bool alive = true;
};

using namespace std;

int field[MAX_N][MAX_N];
Fish fishes[MAX_F], shark;
int ret;

int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, -1, -1, -1, 0, 1, 1, 1};

void copyFish(Fish src[MAX_F], Fish dst[MAX_F]) {
    for(int i = 1; i <= 16; ++i)
        dst[i] = src[i];
}

void copyField(int src[MAX_N][MAX_N], int dst[MAX_N][MAX_N]) {
    for(int i = 0; i < MAX_N; ++i) {
        for(int j = 0; j < MAX_N; ++j) {
            dst[i][j] = src[i][j];
        }
    }
}

bool validate(int row, int col) {
    return row >= 0 && row < MAX_N && col >= 0 && col < MAX_N;
}

void moveFish(int fish_num) {
    Fish &fish = fishes[fish_num];
    for(int i = 0; i < 8; ++i) {
        int nr = fish.row + dr[(fish.dir+i) % 8];
        int nc = fish.col + dc[(fish.dir+i) % 8];
        if(!validate(nr, nc) || (shark.row == nr && shark.col == nc))
            continue;
        if(!field[nr][nc]) {
            field[fish.row][fish.col] = 0;
        } else {
            field[fish.row][fish.col] = field[nr][nc];
            fishes[field[nr][nc]].row = fish.row;
            fishes[field[nr][nc]].col = fish.col;
        }
        fish.row = nr; fish.col = nc;
        fish.dir = (fish.dir+i) % 8;
        field[fish.row][fish.col] = fish_num;
        break;
    }
}

void moveAllFish() {
    for(int i = 1; i < MAX_F; ++i) {
        if(fishes[i].alive)
            moveFish(i);
    }
}

void dfs(int point) {
    shark.dir = fishes[field[shark.row][shark.col]].dir;
    point += field[shark.row][shark.col];
    fishes[field[shark.row][shark.col]].alive = false;
    field[shark.row][shark.col] = 0;
    moveAllFish();

    int tmp_field[MAX_N][MAX_N];
    Fish tmp_fishes[MAX_F], tmp_shark;
    copyField(field, tmp_field);
    copyFish(fishes, tmp_fishes);
    tmp_shark = shark;

    int nr = shark.row + dr[shark.dir];
    int nc = shark.col + dc[shark.dir];

    while (validate(nr, nc)) {
        if (field[nr][nc]) {
            shark.row = nr;
            shark.col = nc;
            dfs(point);
            copyField(tmp_field, field);
            copyFish(tmp_fishes, fishes);
            shark = tmp_shark;
        }
        nr += dr[shark.dir];
        nc += dc[shark.dir];
    }

    ret = max(ret, point);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    for(int i = 0; i < 16; ++i) {
        cin >> a >> b;
        fishes[a].row = i / MAX_N; fishes[a].col = i % MAX_N;
        fishes[a].dir = b-1;
        field[fishes[a].row][fishes[a].col] = a;
    }
    shark.row = 0; shark.col = 0;
    dfs(0);

    cout << ret << "\n";

    return 0;
}