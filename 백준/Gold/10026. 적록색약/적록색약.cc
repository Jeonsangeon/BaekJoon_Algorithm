#include <iostream>
#include <queue>

using namespace std;

#define X first
#define Y second

char field[101][101];
bool visit[101][101];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n;

void bfs(pair<int, int> loc){
    queue<pair<int, int>> Q;
    Q.push(loc);
    visit[loc.X][loc.Y] = 1;

    while(!Q.empty()){
        pair<int, int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; ++dir){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if(field[nx][ny] != field[cur.X][cur.Y] || visit[nx][ny])
                continue;
            visit[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie();

    cin >> n;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> field[i][j];
        }
    }
    int no_RGB = 0, yes_RGB = 0;
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(!visit[i][j]){
                ++no_RGB;
                bfs({i, j});
            }
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(field[i][j] == 'G')
                field[i][j] = 'R';
            visit[i][j] = false;
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(!visit[i][j]){
                ++yes_RGB;
                bfs({i, j});
            }
        }
    }

    cout << no_RGB << " " << yes_RGB << "\n";


    return 0;
}