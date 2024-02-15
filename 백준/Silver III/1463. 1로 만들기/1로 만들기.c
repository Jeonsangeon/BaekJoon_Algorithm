#include <stdio.h>
#define min(a, b) (a < b ? a : b)

int main() {
    int dp[1000001];
    int i, n;
    scanf("%d", &n);
    dp[2] = 1;
    dp[3] = 1;
    i = 4;
    while(i <= n){
        dp[i] = dp[i-1] + 1;
        if(i%3 == 0){
            dp[i] = min(dp[i], dp[i/3]+1);
        }
        if(i%2 == 0){
            dp[i] = min(dp[i], dp[i/2]+1);
        }
        ++i;
    }
    printf("%d", dp[n]);
    
    return 0;
}