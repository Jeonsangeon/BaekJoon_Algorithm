#include <iostream>

using namespace std;

int N;
int dp[1000];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    dp[1] = 1; dp[2] = 2;
    for(int i = 3; i <= N; ++i)
        dp[i] = (dp[i-2] + dp[i-1]) % 10007;
    
    cout << dp[N] << "\n";

    return 0;
}