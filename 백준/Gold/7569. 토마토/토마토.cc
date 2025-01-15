#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX_NUM 100

using namespace std;

int N, M, H;
int box[MAX_NUM][MAX_NUM][MAX_NUM];
int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N >> H;
    queue<vector<int>> Q;
    int ans = 0;
    for(int i = 0; i < H; ++i){
        for(int j = 0; j < N; ++j){
            for(int k = 0; k < M; ++k){
                cin >> box[i][j][k];
                if(box[i][j][k] == 1){
                    Q.push({i, j, k});
                }
            }
        }
    }

    while(!Q.empty()){
        vector<int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 6; ++dir){
            int nx = cur[2] + dx[dir];
            int ny = cur[1] + dy[dir];
            int nz = cur[0] + dz[dir];
            if(nx < 0 || ny < 0 || nz < 0 || nx >= M || ny >= N || nz >= H)
                continue;
            if(box[nz][ny][nx] == 0){
                box[nz][ny][nx] = box[cur[0]][cur[1]][cur[2]] + 1;
                
                Q.push({nz, ny, nx});
            }
            
        }
    }

    for(int i = 0; i < H; ++i){
        for(int j = 0; j < N; ++j){
            for(int k = 0; k < M; ++k){
                ans = max(ans, box[i][j][k]);
                if(box[i][j][k] == 0){
                    cout << -1 << "\n";
                    return 0;
                }
            }
        }
    }

    cout << ans-1 << "\n";

    return 0;
}