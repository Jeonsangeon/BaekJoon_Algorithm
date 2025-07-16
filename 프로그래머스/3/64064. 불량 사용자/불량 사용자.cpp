#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;

int ret;
vector<vector<int>> candidate(8);
set<vector<int>> result;

void recur(int cur, int depth, vector<int> tmp) {
    if(cur == depth) {
        set<int> tmp_s(tmp.begin(), tmp.end());
        if(depth == tmp_s.size()) {
            vector<int> tmp_v(tmp_s.begin(), tmp_s.end());
            result.insert(tmp_v);
        }
        return;
    }
    for(int i = 0; i < candidate[cur].size(); ++i) {
        tmp.push_back(candidate[cur][i]);
        recur(cur+1, depth, tmp);
        tmp.pop_back();
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    for(int k = 0; k < banned_id.size(); ++k) {
        for(int i = 0; i < user_id.size(); ++i) {
            string cur = banned_id[k];
            if(cur.size() != user_id[i].size())
                continue;
            bool flag = true;
            for(int j = 0; j < cur.size(); ++j) {
                if(cur[j] == '*')
                    continue;
                if(cur[j] != user_id[i][j]) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                candidate[k].push_back(i);
            }
        }
    }
    recur(0, banned_id.size(), {});
    
    return result.size();
}