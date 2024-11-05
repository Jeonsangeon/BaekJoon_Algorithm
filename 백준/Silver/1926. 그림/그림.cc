#include <iostream>
#include <queue>

using namespace std;

#define X first
#define Y second

int board[501][501] = {0};
int vis[501][501];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int n, m;

int dfs(pair<int, int> loc){
    int area = 0;
    queue<pair<int, int>> Q;
    vis[loc.X][loc.Y] = 1;
    Q.push(loc);

    while(!Q.empty()){
        pair<int, int> cur = Q.front(); Q.pop();
        ++area;
        for(int dir = 0; dir < 4; ++dir){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if(vis[nx][ny] || board[nx][ny] != 1)
                continue;
            vis[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }

    return area;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> board[i][j];
    
    int max_area = 0, count = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(board[i][j] && !vis[i][j]){
                ++count;
                int cur_area = dfs({i, j});
                if(cur_area > max_area)
                    max_area = cur_area;
            }
        }
    }

    cout << count << "\n" << max_area << "\n";

    return 0;
}