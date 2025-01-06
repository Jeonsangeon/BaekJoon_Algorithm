#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

#define MAX_AREA 100
#define X first
#define Y second

using namespace std;

bool visited[MAX_AREA][MAX_AREA];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int bfs(int m, int n, pair<int, int> loc, vector<vector<int>> picture) {
    queue<pair<int, int>> Q;
    int color = picture[loc.X][loc.Y];
    int area = 0;
    Q.push(loc);
    visited[loc.X][loc.Y] = true;
    
    while(!Q.empty()){
        pair<int, int> cur = Q.front(); Q.pop();
        ++area;
        for(int dir = 0; dir < 4; ++dir){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= m || ny >= n)
                continue;
            if(visited[nx][ny] || picture[nx][ny] != color)
                continue;
            visited[nx][ny] = true;
            Q.push({nx, ny});
        }
    }
    
    return area;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for (int i = 0; i < MAX_AREA; i++) {
        for (int j = 0; j < MAX_AREA; j++) {
            visited[i][j] = false;
        }
    }
    
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j){
            if(visited[i][j] || picture[i][j] == 0)
                continue;
            ++number_of_area;
            max_size_of_one_area = max(max_size_of_one_area, bfs(m, n, {i, j}, picture));
        }
            
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    
    return answer;
}