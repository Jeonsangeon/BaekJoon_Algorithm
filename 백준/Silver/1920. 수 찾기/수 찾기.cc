#include <iostream>
#include <algorithm>

#define MAX_N 100000

using namespace std;

int n, m;
int arr[MAX_N];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr, arr+n);
    cin >> m;
    int tmp;
    while(m--){
        cin >> tmp;
        cout << binary_search(arr, arr+n, tmp) << "\n";
    }

    return 0;
}