#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int board[1001][1001] = {0};
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int m, n;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<pair<int, int>> starts;

    cin >> m >> n;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> board[i][j];
            if(board[i][j] == 1)
                starts.push_back({i, j});
        }
    }

    queue<pair<int, int>> Q;
    for(pair<int, int> start : starts){
        Q.push(start);
    }

    while(!Q.empty()){
        pair<int, int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; ++dir){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if(board[nx][ny] != 0)
                continue;
            board[nx][ny] = board[cur.first][cur.second] + 1;
            Q.push({nx, ny});
        }
    }

    int max_day = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(!board[i][j]){
                cout << -1 << '\n';
                return 0;
            } 
            if(board[i][j] > max_day)
                max_day = board[i][j];
        }
    }

    cout << max_day-1 << "\n";

    return 0;
}