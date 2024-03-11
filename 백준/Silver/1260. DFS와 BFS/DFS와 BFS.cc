#include <iostream>
#include <set>
#include <vector>
#include <stack>
#include <deque>

using namespace std;

vector<int> dfs(int start, vector<set<int>> graph, vector<bool> visited)
{
    vector<int> result;
    stack<int> st;
    st.push(start);

    while(!st.empty()){
        int current = st.top();
        st.pop();
        if(!visited[current]){
            result.push_back(current);
            visited[current] = true;
            for(auto iter = graph[current].rbegin(); iter != graph[current].rend(); ++iter){
                if(!visited[*iter]){
                    st.push(*iter);
                }
            }
        }
    }

    return result;
}

vector<int> bfs(int start, vector<set<int>> graph, vector<bool> visited)
{
    vector<int> result;
    deque<int> dq;
    dq.push_back(start);
    visited[start] = true;

    while (!dq.empty()){
        int value = dq.front();
        dq.pop_front();
        result.push_back(value);
        for (int i: graph[value]){
            if (!visited[i]){
                dq.push_back(i);
                visited[i] = true;
            }
        }
    }
    return result;
}

int main()
{
    int N, M, V, x, y;
    cin >> N >> M >> V;

    vector<int> result_dfs, result_bfs;
    vector<set<int>> graph(N + 1);
    vector<bool> visited(N + 1, false);

    for (int i = 0; i < M; ++i) {
        cin >> x >> y;
        graph[x].insert(y);
        graph[y].insert(x);
    }

    result_dfs = dfs(V, graph, visited);
    result_bfs = bfs(V, graph, visited);

    for (int i : result_dfs){
        cout << i << " ";
    }
    printf("\n");
    for (int i : result_bfs){
        cout << i << " ";
    }
    printf("\n");

    return 0;
}
