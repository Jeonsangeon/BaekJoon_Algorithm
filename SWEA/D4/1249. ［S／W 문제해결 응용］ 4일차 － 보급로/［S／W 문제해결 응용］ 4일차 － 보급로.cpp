#include <iostream>
#include <queue>
#include <algorithm>

#define MAX_INT 2147483647
#define MAX_NUM 100
#define X first
#define Y second

using namespace std;

int N;
int field[MAX_NUM][MAX_NUM], dist[MAX_NUM][MAX_NUM];

int dx[] = {0, -1, 1, 0};
int dy[] = {1, 0, 0, -1};

void bfs() {
    queue<pair<int, int>> Q;
    Q.push({0, 0});
    dist[0][0] = 0;

    while(!Q.empty()){
        pair<int, int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; ++dir){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= N || ny >= N)
                continue;
            int ndist = dist[cur.X][cur.Y] + field[nx][ny];
            if(ndist < dist[nx][ny]){
                dist[nx][ny] = ndist;
                Q.push({nx, ny});
            }
        }
    }
}

int main(int argc, char** argv)
{
	int test_case, T, answer;
    char tmp;
	cin >> T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> N;
        answer = 0;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                cin >> tmp;
                field[i][j] = tmp - '0';
                dist[i][j] = MAX_INT;
            }
        }
        bfs();

        cout << "#" << test_case << " " << dist[N-1][N-1] << "\n";
	}

	return 0;
}