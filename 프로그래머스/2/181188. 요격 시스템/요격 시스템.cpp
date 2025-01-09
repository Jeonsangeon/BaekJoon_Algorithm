#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(vector<int> a, vector<int> b) {
    if(a[1] == b[1]) return a[0] < b[0];
    return a[1] < b[1];
}

//GREEDY Alg
int solution(vector<vector<int>> targets) {
    int answer = 0;
    sort(targets.begin(), targets.end(), compare);
    
    int cur = 0;
    for(int i = 0; i < targets.size(); ++i) {
        if(cur > targets[i][0])
            continue;
        cur = targets[i][1];
        ++answer;
    }
    
    return answer;
}