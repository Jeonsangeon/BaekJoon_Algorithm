#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <array>
#include <algorithm>
#include <cstdlib>

#define MAX_N 101

using namespace std;

int N;
bool edge[MAX_N][MAX_N];
bool visited[MAX_N];

int bfs() {
    memset(visited, 0, sizeof(visited));
    int count = 0;
    queue<int> q;
    q.push(1);
    visited[1] = true;
    
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        ++count;
        for(int i = 0; i <= N; ++i) {
            if(!edge[cur][i] || visited[i])
                continue;
            visited[i] = true;
            q.push(i);
        }
    }
    
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int ret = 101; N = n;
    for (int i = 0; i < n - 1; ++i) {
        edge[wires[i][0]][wires[i][1]] = true;
        edge[wires[i][1]][wires[i][0]] = true;
    }

    for (int i = 0; i < n - 1; ++i) {
        edge[wires[i][0]][wires[i][1]] = false;
        edge[wires[i][1]][wires[i][0]] = false;

        int group1 = bfs();
        int group2 = n - group1;
        
        ret = min(ret, abs(group1 - group2));

        edge[wires[i][0]][wires[i][1]] = true;
        edge[wires[i][1]][wires[i][0]] = true;
    }
    
    return ret;
}
