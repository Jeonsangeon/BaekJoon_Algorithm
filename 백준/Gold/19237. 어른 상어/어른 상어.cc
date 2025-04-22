#include <iostream>
#include <array>
#include <unordered_map>

#define MAX_N 20
#define MAX_M 401

using namespace std;

struct Shark{
    array<int, 2> loc;
    int cur_dir;
    unordered_map<int, array<int, 4>> dir;
    bool alive = true;
};

int N, M, K, ret;
int field[MAX_N][MAX_N];
int smell[MAX_N][MAX_N];
Shark sharks[MAX_M];

int dr[] = {0, -1, 1, 0, 0};
int dc[] = {0, 0, 0, -1, 1};

bool gameOver() {
    for(int i = 2; i <= M; ++i) {
        if(sharks[i].alive)
            return false;
    }
    return true;
}

bool validate(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < N;
}

void updateSmell() {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            if(smell[i][j]) {
                --smell[i][j];
                if(!smell[i][j])
                    field[i][j] = 0;
            }
        }
    }
}

void move(int index) {
    Shark &shark = sharks[index];
    int candidate = 0;
    for(int i = 0; i < 4; ++i) {
        int nr = shark.loc[0] + dr[shark.dir[shark.cur_dir][i]];
        int nc = shark.loc[1] + dc[shark.dir[shark.cur_dir][i]];
        if(!validate(nr, nc))
            continue;
        if(field[nr][nc]) {
            if(!candidate && field[nr][nc] == index) {
                candidate = shark.dir[shark.cur_dir][i];
            }
            continue;
        }
        shark.loc = {nr, nc};
        shark.cur_dir = shark.dir[shark.cur_dir][i];
        return;
    }

    if(candidate) {
        int nr = shark.loc[0] + dr[candidate];
        int nc = shark.loc[1] + dc[candidate];
        shark.loc = {nr, nc};
        shark.cur_dir = candidate;
        smell[nr][nc] = K+1;
        return;
    }

    shark.alive = false;
}

void moveAll() {
    for(int i = 1; i <= M; ++i) {
        if(sharks[i].alive)
            move(i);
    }

    for(int i = 1; i <= M; ++i) {
        Shark &shark = sharks[i];
        if(shark.alive) {
            if(field[shark.loc[0]][shark.loc[1]]) {
                if(field[shark.loc[0]][shark.loc[1]] != i) {
                    shark.alive = false;
                    continue;
                }
            }
            field[shark.loc[0]][shark.loc[1]] = i;
            smell[shark.loc[0]][shark.loc[1]] = K+1;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cin >> field[i][j];
            if(field[i][j]) {
                sharks[field[i][j]].loc = {i, j};
                smell[i][j] = K;
            }
        }
    }

    for(int i = 1; i <= M; ++i)
        cin >> sharks[i].cur_dir;

    for(int i = 1; i <= M; ++i) {
        for(int j = 1; j <= 4; ++j) {
            array<int, 4> tmp;
            for(int k = 0; k < 4; ++k) {
                cin >> tmp[k];
            }
            sharks[i].dir[j] = tmp;
        }
    }
    
    while(ret <= 1000) {
        if(gameOver())
            break;
        moveAll();
        updateSmell();
        ++ret;
    }
    
    cout << (ret > 1000 ? -1 : ret) << "\n";

    return 0;
}