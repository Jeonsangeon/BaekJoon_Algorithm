#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

int ret;
vector<array<int, 2>> avaliable;

int solution(int n, vector<int> stations, int w) {
    for(int i = 0; i < stations.size(); ++i) {
        int left = stations[i] - w > 0 ? stations[i] - w : 1;
        int right = stations[i] + w <= n? stations[i] + w : n;
        if(avaliable.empty()) {
            avaliable.push_back({left, right});
            continue;
        }
        if(left <= avaliable[avaliable.size()-1][1])
            avaliable[avaliable.size()-1][1] = right;
        else
            avaliable.push_back({left, right});
    }
        
    int cur = 1;
    for(array<int, 2> a : avaliable) {
        if(cur > n)
            break;
        while(cur < a[0]) {
            ++ret;
            cur += (2 * w) + 1;
        }
        if(a[0] <= cur && cur <= a[1])
            cur = a[1] + 1;
    }
    
    while(cur <= n) {
        ++ret;
        cur += (2 * w) + 1;
    }

    return ret;
}