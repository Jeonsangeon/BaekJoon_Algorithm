#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long solution_helper(const vector<int>& a, int l, int r) {
    long long take1 = 0, take2 = 0;
    for(int i = l; i <= r; ++i) {
        long long cur = max(take1, take2 + a[i]);
        take2 = take1;
        take1 = cur;
    }
    
    return take1;
}

int solution(vector<int> sticker) {
    int N = sticker.size();
    
    if (N == 1) 
        return sticker[0];
    if (N == 2)
        return max(sticker[0], sticker[1]);
    
    long long caseA = solution_helper(sticker, 0, N-2);
    long long caseB = solution_helper(sticker, 1, N-1);

    return max(caseA, caseB);
}