#include <iostream>
#include <algorithm>

#define MAX_N 11
#define MAX_H 31
#define INF 0x3fffffff

using namespace std;

int N, M, H;
bool ladder[MAX_H][MAX_N];
int ret = INF;

bool check() {
    for (int i = 1; i <= N; ++i) {
        int cur_line = i;
        for (int j = 1; j <= H; ++j) {
            if (ladder[j][cur_line]) ++cur_line;
            else if (cur_line > 1 && ladder[j][cur_line - 1]) --cur_line;
        }
        if (cur_line != i)
            return false;
    }
    return true;
}

bool dfs(int max_depth, int depth) {
    if (max_depth == depth) {
        if (check()) {
            ret = min(ret, depth);
            return true;
        }
        return false;
    }

    bool flag = false;
    for (int j = 1; j <= H; ++j) {
        for (int i = 1; i < N; ++i) {
            if (ladder[j][i]) continue;
            if (i > 1 && ladder[j][i - 1]) continue;
            if (i + 1 < N && ladder[j][i + 1]) continue;
            ladder[j][i] = true;
            flag = dfs(max_depth, depth + 1);
            ladder[j][i] = false;
            if (flag) return true;
        }
    }

    return false;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> N >> M >> H;
    for (int i = 0; i < M; ++i) {
        cin >> a >> b;
        ladder[a][b] = true;
    }

    bool flag = false;
    for (int i = 0; i <= 3; ++i) {
        if (dfs(i, 0)) {
            flag = true;
            break;
        }
    }

    if (flag)
        cout << ret << "\n";
    else
        cout << -1 << "\n";

    return 0;
}
