#include <iostream>
#include <cstdlib>
#include <cstring>

#define MAX_N 100

using namespace std;

int N, L, ret;
int map[MAX_N][MAX_N];

void check(int line[MAX_N]) {
    bool install[N];
    memset(install, 0, sizeof(install));

    for(int cur = 0; cur < N-1; ++cur) {
        if(abs(line[cur]-line[cur+1]) > 1)
            return;
        if(line[cur] == line[cur+1])
            continue;
        else if(line[cur] > line[cur+1]) {
            int st = line[cur+1];
            for(int i = 0; i < L; ++i) {
                if(cur+1+i >= N || st != line[cur+1+i])
                    return;
                install[cur+1+i] = true;
            }
        } else {
            int st = line[cur];
            for(int i = 0; i < L; ++i) {
                if(cur-i < 0 || install[cur-i] || st != line[cur-i])
                    return;
                install[cur-i] = true;
            }
        }
    }
    ++ret;
    return;
}

void solve() {
    int line_r[MAX_N], line_c[MAX_N];
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            line_r[j] = map[i][j];
            line_c[j] = map[j][i];
        }
        check(line_r);
        check(line_c);
    }
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> L;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cin >> map[i][j];
        }
    }

    solve();

    cout << ret << "\n";

    return 0;
}