#include <iostream>
#include <queue>
#include <string>

using namespace std;

#define X first
#define Y second

string board[101];
int dist[101][101] = {0};
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n, m;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        cin >> board[i];

    queue<pair<int, int>> Q;
    dist[0][0] = 1;
    Q.push({0, 0});

    while(!Q.empty()){
        pair<int, int> cur = Q.front(); Q.pop();

        for(int dir = 0; dir < 4; ++dir){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if(board[nx][ny] != '1' || dist[nx][ny])
                continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }

    cout << dist[n-1][m-1] << "\n";

    return 0;
}