#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool canCross(const vector<int>& stones, int k, int p) {
    int cnt = 0;
    for (int x : stones) {
        if (x - p < 0) {
            if (++cnt >= k) 
                return false;
        } else {
            cnt = 0;
        }
    }
    
    return true;
}

int solution(vector<int> stones, int k) {
    int lo = 0, hi = *max_element(stones.begin(), stones.end());
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (canCross(stones, k, mid)) 
            lo = mid; 
        else 
            hi = mid - 1;
    }
    
    return lo;
}