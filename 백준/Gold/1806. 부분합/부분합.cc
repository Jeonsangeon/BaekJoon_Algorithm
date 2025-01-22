#include <iostream>
#include <algorithm>

#define MAX_N 100000
#define MAX_INT 0x7fffffff

using namespace std;

int n, s, tot;
int arr[MAX_N];
int min_cnt = MAX_INT;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> s;
    for(int i = 0; i < n; ++i) cin >> arr[i];

    tot = arr[0];
    int en = 0;
    for(int st = 0; st < n; ++st){
        while(en < n && tot < s) {
            ++en;
            if(en != n) tot += arr[en];
        }
        if(en == n)
            break;
        min_cnt = min(min_cnt, en - st + 1);
        tot -= arr[st];
    }

    if(min_cnt == MAX_INT)
        cout << 0 << "\n";
    else
        cout << min_cnt << "\n";

    return 0;
}
