#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> gems) {
    int N = gems.size();
    
    unordered_set<string> kinds_gem(gems.begin(), gems.end());
    int kinds_count = kinds_gem.size();
    
    unordered_map<string, int> gem_cnt;
    int unique = 0;
    
    int left = 0;
    int best_len = N+1;
    pair<int, int> ret = {0, N - 1};
    
    for(int right = 0; right < N; ++right) {
        if(gem_cnt[gems[right]] == 0)
            ++unique;
        ++gem_cnt[gems[right]];
        
        while(kinds_count == unique && left <= right) {
            if(right - left + 1 < best_len) {
                best_len = right  - left + 1;
                ret = {left, right};
            }
            
            --gem_cnt[gems[left]];
            if(gem_cnt[gems[left]] == 0)
                --unique;
            ++left;
        }
    }
    
    return {ret.first + 1, ret.second + 1};
}