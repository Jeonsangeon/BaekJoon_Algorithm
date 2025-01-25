#include <iostream>

#define MAX_N 1001
#define MOD 10007

using namespace std;

int comb[MAX_N][MAX_N];
int n, m;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		comb[i][0] = comb[i][i] = 1;
		for(int j = 1; j < i; ++j)
			comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % MOD;
	}
	cout << comb[n][m];
}