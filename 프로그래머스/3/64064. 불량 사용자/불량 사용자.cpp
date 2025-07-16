#include <string>
#include <vector>
#include <set>

using namespace std;

void dfs(int idx, const vector<vector<int>>& candidate, set<int>& current, set<set<int>>& results) {
    if (idx == candidate.size()) {
        results.insert(current);
        return;
    }

    for (int uid : candidate[idx]) {
        if (current.count(uid)) continue;
        current.insert(uid);
        dfs(idx + 1, candidate, current, results);
        current.erase(uid);
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    vector<vector<int>> candidate(banned_id.size());
    
    for (int i = 0; i < banned_id.size(); ++i) {
        for (int j = 0; j < user_id.size(); ++j) {
            if (user_id[j].size() != banned_id[i].size()) continue;

            bool match = true;
            for (int k = 0; k < banned_id[i].size(); ++k) {
                if (banned_id[i][k] == '*') continue;
                if (banned_id[i][k] != user_id[j][k]) {
                    match = false;
                    break;
                }
            }
            if (match) candidate[i].push_back(j);
        }
    }

    set<set<int>> results;
    set<int> current;
    dfs(0, candidate, current, results);

    return results.size();
}
