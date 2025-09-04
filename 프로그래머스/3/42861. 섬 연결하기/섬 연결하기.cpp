#include <string>
#include <vector>
#include <iostream>
#include <queue>

#define MAX_N 100

using namespace std;

int parent[MAX_N];
int N;

int Find(int x) {
    if(x == parent[x])
        return x;
    else
        return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
	int A = Find(a);
	int B = Find(b);
	
	parent[B] = A;
}

int solution(int n, vector<vector<int>> costs) {
    int ret = 0; N = n;
    
    priority_queue<pair<int, pair<int, int>>> pq;
    for(vector<int> cost : costs)
        pq.push({-cost[2], {cost[0], cost[1]}});
    
    for(int i = 0; i < N; ++i)
        parent[i] = i;
    
    int connect = 0;
    while(connect < n-1) {
        int cost = -pq.top().first;
        pair<int, int> nodes = pq.top().second;
        pq.pop();
        
        if(Find(nodes.first) == Find(nodes.second))
            continue;
        ++connect;
        ret += cost;
        Union(nodes.first, nodes.second);
    }
    
    return ret;
}