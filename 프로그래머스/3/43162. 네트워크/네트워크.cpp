#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>

#define MAX_N 200

using namespace std;

bool check[MAX_N];
vector<vector<int>> graph;
int N;

void bfs(int node) {
    queue<int> q;
    q.push(node);
    check[node] = true;
    
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        
        for(int next = 0; next < N; ++next) {
            if(!graph[cur][next] || check[next])
                continue;
            q.push(next);
            check[next] = true;
        }        
    }
}

int solution(int n, vector<vector<int>> computers) {
    int ret = 0;
    N = n; graph = computers;
    for(int i = 0; i < N; ++i) {
        if(!check[i]) {
            bfs(i);
            ++ret;
        }
    }
    
    return ret;
}