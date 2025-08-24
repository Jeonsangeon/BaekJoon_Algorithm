#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<string> ret;

int ticket_count;
bool flag;
unordered_map<string, vector<string>> um_id;
unordered_map<string, vector<bool>> um_vis;

void dfs(string cur_id, int cur_count, vector<string> order) {
    if(flag)
        return;
    
    if(cur_count == ticket_count) {
        ret = order;
        flag = true;
        return;
    }
    
    for(int i = 0; i < um_id[cur_id].size(); i++) {
        if(!um_vis[cur_id][i]) {
            um_vis[cur_id][i] = true;
            order.push_back(um_id[cur_id][i]);
            dfs(um_id[cur_id][i], cur_count+1, order);
            order.pop_back();
            um_vis[cur_id][i] = false;
        }
        if(flag)
            return;
    }
}


vector<string> solution(vector<vector<string>> tickets) {
    ticket_count = tickets.size();
    
    for(vector<string> ticket : tickets) {
        if(um_id.find(ticket[0]) != um_id.end()) {
            um_id[ticket[0]].push_back(ticket[1]);
            um_vis[ticket[0]].push_back(false);
        }
        else {
            um_id[ticket[0]] = {ticket[1]};
            um_vis[ticket[0]] = {false};
        }
    }
    
    for(auto &i : um_id)
        sort(i.second.begin(), i.second.end());   
    
    dfs("ICN", 0, {"ICN"});
    
    for(string i : ret)
        cout << i << " ";
    
    // for(string i : um_id["ICN"])
    //     cout << i << " ";
    
    return ret;
}