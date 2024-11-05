#include <iostream>
#include <queue>

using namespace std;

char field[1001][1001];
int J_time[1001][1001] = {0};
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

int r, c;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int, int>> Q;
    vector<pair<int, int>> F;
    
    cin >> r >> c;
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            cin >> field[i][j];
            if(field[i][j] == 'J'){
                Q.push({i, j});
                J_time[i][j] = 1;
            }
            else if(field[i][j] == 'F')
                F.push_back({i, j});
        }
    }

    for(pair<int, int> f : F)
        Q.push(f);

    while(!Q.empty()){
        pair<int, int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; ++dir){
            int nr = cur.first + dr[dir];
            int nc = cur.second + dc[dir];
            if(field[cur.first][cur.second] == 'J'){
                if(nr < 0 || nr >= r || nc < 0 || nc >= c){
                    cout << J_time[cur.first][cur.second] << '\n';
                    return 0;
                }
                if(field[nr][nc] != '.')
                    continue;
                Q.push({nr, nc});
                field[nr][nc] = 'J';
                J_time[nr][nc] = J_time[cur.first][cur.second] + 1;
            } else{
                if(nr < 0 || nr >= r || nc < 0 || nc >= c)
                    continue;
                if(field[nr][nc] == '#' || field[nr][nc] == 'F')
                    continue;
                Q.push({nr, nc});
                field[nr][nc] = 'F';
            }
        }
    }
    
    cout << "IMPOSSIBLE\n";

    return 0;
}