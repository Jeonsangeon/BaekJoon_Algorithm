#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> ret;

vector<int> solution(int n, int s) {
    if(s < n)
        return {-1};
    
    for(int i = 0; i < n; ++i)
        ret.push_back(s/n);
    s -= ((s/n) * n);
    int cur = 0;
    while((s--) > 0) {
        ++ret[cur++];
    }
    sort(ret.begin(), ret.end());
    
    return ret;
}