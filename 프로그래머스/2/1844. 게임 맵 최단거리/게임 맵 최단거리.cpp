#include <vector>
#include <iostream>
#include <queue>

#define MAX_SIZE 100

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool visited[MAX_SIZE][MAX_SIZE];
int m, n;

using namespace std;

struct item {
    int x;
    int y;
    int distance;
};

int bfs(vector<vector<int> > maps) {
    queue<item> Q;
    Q.push({0, 0, 1});
    visited[0][0] = true;
    
    while(!Q.empty()){
        item cur = Q.front(); Q.pop();
        if(cur.x == m - 1 && cur.y == n - 1)
            return cur.distance;
        for(int dir = 0; dir < 4; ++dir){
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= m || ny >= n)
                continue;
            if(visited[nx][ny] || maps[nx][ny] == 0)
                continue;
            Q.push({nx, ny, cur.distance + 1});
            visited[nx][ny] = true;
        }
    }
    
    return -1;
}

int solution(vector<vector<int>> maps)
{
    m = maps.size();
    n = maps[0].size();
    
    if(maps[m-1][n-2] == 0 && maps[m-2][n-1] == 0)
        return -1;
    
    return bfs(maps);
}