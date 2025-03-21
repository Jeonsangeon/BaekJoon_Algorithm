#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 15;
int N, ret = 0;
int day[MAX_N][2];

void solve(int idx, int currentProfit) {
    if (idx >= N) {
        ret = max(ret, currentProfit);
        return;
    }
    solve(idx + 1, currentProfit);
    if (idx + day[idx][0] <= N)
        solve(idx + day[idx][0], currentProfit + day[idx][1]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> day[i][0] >> day[i][1];

    solve(0, 0);
    cout << ret << "\n";
    
    return 0;
}
