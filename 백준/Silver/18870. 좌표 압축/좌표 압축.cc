#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_N 1000000

using namespace std;

int n;
int arr[MAX_N];
vector<int> tmp, uni;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        tmp.push_back(arr[i]);
    } 
    sort(tmp.begin(), tmp.end());
    for(int i = 0; i < n; ++i){
        if(i == 0 || tmp[i-1] != tmp[i])
            uni.push_back(tmp[i]);
    }
    for(int i = 0; i < n; ++i)
        cout << lower_bound(uni.begin(), uni.end(), arr[i]) - uni.begin() << ' ';

    return 0;
}