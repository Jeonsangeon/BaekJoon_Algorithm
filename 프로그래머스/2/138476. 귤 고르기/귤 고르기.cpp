#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int ret;

int solution(int k, vector<int> tangerine) {
    vector<int> counts;
    sort(tangerine.begin(), tangerine.end());
    for(int i = 0; i < tangerine.size(); ++i) {
        int count = 0, std = tangerine[i];
        while(std == tangerine[i]) {
            ++i; ++count;
        }
        --i;
        counts.push_back(count);
    }
    sort(counts.begin(), counts.end());
    for(int i = counts.size()-1; i >= 0; --i) {
        k -= counts[i];
        ++ret;
        if(k <= 0)
            break;
    }
    
    return ret;
}