#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <array>
#include <cstring>

#define MAX_N 51

using namespace std;

int N;
bool graph[MAX_N][MAX_N];
vector<string> word_list;

int bfs(string target) {
    bool visited[N];
    memset(visited, 0, sizeof(visited));
    priority_queue<array<int, 2>> pq;
    pq.push({0, 0});
    visited[0] = true;
    
    while(!pq.empty()) {
        array<int, 2> cur = pq.top(); pq.pop();
        if(word_list[cur[1]] == target)
            return -cur[0];
        
        for(int i = 0; i < N; ++i) {
            if(!graph[cur[1]][i] || visited[i])
                continue;
            pq.push({cur[0]-1, i});
            visited[i] = true;
        }
    }
    
    return 0;
}

int solution(string begin, string target, vector<string> words) {
    bool flag = false;
    word_list.push_back(begin);
    
    for(string word : words) {
        if(word == target) {
            flag = true;
        }
        word_list.push_back(word);
    }
    
    if(!flag)
        return 0;
    
    N = word_list.size();
    for(int i = 0; i < word_list.size(); ++i) {
        for(int j = 0; j < word_list.size(); ++j) {
            int char_num = 0;
            for(int k = 0; k < begin.size(); ++k) {
                if(word_list[i][k] != word_list[j][k])
                    ++char_num;
            }
            if(char_num == 1) {
                graph[i][j] = true;
                graph[j][i] = true;
            }            
        }
    }
    
    return bfs(target);
}