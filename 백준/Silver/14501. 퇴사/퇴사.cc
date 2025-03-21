#include <iostream>
#include <array>
#include <algorithm>

#define MAX_N 15

using namespace std;

int N, ret = 0;
array<int, 2> day[MAX_N];
bool check[MAX_N];

int calculatePrice() {
    int price = 0;
    for(int i = 0; i < N; ++i) {
        if(check[i])
            price += day[i][1];
    }
    return price;
}

void backtracking(int d) {
    if(d >= N) {
        ret = max(ret, calculatePrice());
        return;
    }
    for(int i = d; i < N; ++i) {
        if(i + day[i][0] <= N) {
            check[i] = true;
            backtracking(i+day[i][0]);
            check[i] = false;
        } else {
            backtracking(i+1);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; ++i)
        cin >> day[i][0] >> day[i][1];
    
    for(int i = 0; i < N; ++i) {
        if(i + day[i][0] <= N) {
            check[i] = true;
            backtracking(i+day[i][0]);
            check[i] = false;
        }
    }

    cout << ret << "\n";

    return 0;
}