#include <iostream>
#include <array>

#define MAX_N 20

using namespace std;

int N, M, K;
int map[MAX_N][MAX_N];
array<int, 2> curLoc;
int dice[] = {0, 0, 0, 0, 0, 0};

int dr[] = {0, 0, -1, 1};
int dc[] = {1, -1, 0, 0};

void moveDice(int dir) {
    int tmp;
    if(dir == 0){
        tmp = dice[1];
        dice[1] = dice[2];
        dice[2] = dice[3];
        dice[3] = dice[0];
        dice[0] = tmp;
    } else if(dir == 1){
        tmp = dice[1];
        dice[1] = dice[0];
        dice[0] = dice[3];
        dice[3] = dice[2];
        dice[2] = tmp;
    } else if(dir == 2){
        tmp = dice[1];
        dice[1] = dice[5];
        dice[5] = dice[3];
        dice[3] = dice[4];
        dice[4] = tmp;
    } else if(dir == 3){
        tmp = dice[1];
        dice[1] = dice[4];
        dice[4] = dice[3];
        dice[3] = dice[5];
        dice[5] = tmp;
    }
}

bool validate(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < M;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> curLoc[0] >> curLoc[1] >> K;
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j)
            cin >> map[i][j];
    int dir;
    for(int i = 0; i < K; ++i) {
        cin >> dir; --dir;
        int nr = curLoc[0] + dr[dir];
        int nc = curLoc[1] + dc[dir];
        if(!validate(nr, nc))
            continue;
        
        moveDice(dir);
        curLoc[0] = nr;
        curLoc[1] = nc;
        
        if(map[curLoc[0]][curLoc[1]] == 0) {
            map[curLoc[0]][curLoc[1]] = dice[3];
        } else {
            dice[3] = map[curLoc[0]][curLoc[1]];
            map[curLoc[0]][curLoc[1]] = 0;
        }
        cout << dice[1] << "\n";
    }
    
    return 0;
}
