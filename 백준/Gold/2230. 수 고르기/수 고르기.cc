#include <iostream>
#include <algorithm>

#define MAX_INT 0x7fffffff
#define MAX_N 100000

using namespace std;

int n, m;
int arr[MAX_N];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr, arr+n);
    int mn = MAX_INT, en = 0;
    for(int st = 0; st < n; ++st){
        while(en < n && arr[en] - arr[st] < m) ++en;
        if(en == n) break;
        mn = min(mn, arr[en] - arr[st]);
    }

    cout << mn << "\n";

    return 0;
}