#include <iostream>
#include <array>

#define MAX_F 101

using namespace std;

struct Shark {
    int speed;
    int dir;
    int size;
};

int R, C, M, ret;
int r, c, s, d, z;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int field[MAX_F][MAX_F];
Shark shark_pool[MAX_F * MAX_F];
int shark_idx = 1;

int cur_loc = 0;

bool validate(int r, int c) {
    return r > 0 && r <= R && c > 0 && c <= C;
}

void move_sharks() {
    int tmp[MAX_F][MAX_F] = {0};

    for(int i = 1; i <= R; ++i) {
        for(int j = 1; j <= C; ++j) {
            if(!field[i][j]) continue;

            int shark_index = field[i][j];
            Shark &shark = shark_pool[shark_index];
            int r = i, c = j;
            int s = shark.speed;

            if (shark.dir == 0 || shark.dir == 2)
                s %= (R - 1) * 2;
            else // 좌우
                s %= (C - 1) * 2;

            for (int step = 0; step < s; ++step) {
                int nr = r + dr[shark.dir];
                int nc = c + dc[shark.dir];

                if (!validate(nr, nc)) {
                    shark.dir = (shark.dir + 2) % 4;
                    nr = r + dr[shark.dir];
                    nc = c + dc[shark.dir];
                }

                r = nr;
                c = nc;
            }

            if (!tmp[r][c]) {
                tmp[r][c] = shark_index;
            } else {
                if (shark_pool[tmp[r][c]].size < shark.size)
                    tmp[r][c] = shark_index;
            }
        }
    }
    for(int i = 1; i <= R; ++i)
        for(int j = 1; j <= C; ++j)
            field[i][j] = tmp[i][j];
}

void move_human() {
    ++cur_loc;
    for(int i = 1; i <= R; ++i) {
        if(field[i][cur_loc]) {
            ret += shark_pool[field[i][cur_loc]].size;
            field[i][cur_loc] = 0;
            break;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C >> M;
    for(int i = 0; i < M; ++i) {
        cin >> r >> c >> s >> d >> z;
        if(d == 1) {
            d = 0;
        } else if(d == 3) {
            d = 1;
        } else if(d == 4) {
            d = 3;
        }
        shark_pool[shark_idx] = {s, d, z};
        field[r][c] = shark_idx++;
    }
    
    while(cur_loc < C) {
        move_human();
        move_sharks();
    }

    cout << ret << "\n";

    return 0;
}