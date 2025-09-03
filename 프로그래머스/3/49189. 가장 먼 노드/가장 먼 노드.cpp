#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

#define INF 0x3fffffff

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int ret = 0;
    
    vector<vector<bool>> node(n+1, vector<bool>(n+1, false));
    for(vector<int> e : edge) {
        node[e[0]][e[1]] = true;
        node[e[1]][e[0]] = true;
    }
    
    priority_queue<pair<int, int>> pq;
    
    vector<int> dist(n+1, INF);
    dist[1] = 0;
    pq.push({0, 1});
    
    int max_dist = 0;
    while(!pq.empty()) {
        int cur_dist = -pq.top().first;
        int cur_node = pq.top().second;
        max_dist = max(max_dist, cur_dist);
        pq.pop();
        
        if(cur_dist != dist[cur_node]) continue;
        for(int i = 0; i < n+1; ++i) {
            if(node[cur_node][i]) {
                int nxt_dist = cur_dist + 1;
                if(nxt_dist < dist[i]) {
                    dist[i] = nxt_dist;
                    pq.push({-nxt_dist, i});
                }
            }
        }
    }
        
    for(int i = 2; i < n+1; ++i)
        if(dist[i] == max_dist)
            ++ret;
    
    return ret;
}