#include <iostream>

#define MAX_N 20

using namespace std;

int N, S;
int num[MAX_N];
int ans = 0;

void bt(int cur, int tot) {
    if(cur == N){
        if(tot == S)
            ++ans;
        return;
    }
    bt(cur+1, tot);
    bt(cur+1, tot+num[cur]);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> S;
    for(int i = 0; i < N; ++i)
        cin >> num[i];

    bt(0, 0);

    if(S == 0)
        --ans;
        
    cout << ans << "\n";

    return 0;
}