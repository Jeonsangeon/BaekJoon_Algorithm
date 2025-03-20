#include <iostream>

#define MAX_A 1000000

using namespace std;

int N, B, C;
int A[MAX_A];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; ++i)
        cin >> A[i];
    cin >> B >> C;

    long long ret = N;
    for(int i = 0; i < N; ++i) {
        A[i] -= B;
        if(A[i] <= 0)
            continue;
        ret += (A[i]/C);
        if(A[i]%C)
            ret += 1;
    }

    cout << ret << "\n";

    return 0;
}