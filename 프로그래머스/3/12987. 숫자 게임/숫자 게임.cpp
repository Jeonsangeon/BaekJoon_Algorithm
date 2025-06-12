#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int ret;

int solution(vector<int> A, vector<int> B) {
    int team_len = A.size(), cur = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    for(int i = 0; i < team_len; ++i) {
        while(cur < team_len) {
            if(B[cur] > A[i]) {
                ++ret; 
                ++cur;
                break;
            }
            ++cur;
        }
    }

    return ret;
}