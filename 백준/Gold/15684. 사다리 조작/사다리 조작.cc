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
        if (cur_line != i) return false;
    }
    return true;
}

bool dfs(int max_depth, int depth, int row, int col) {
    if (depth == max_depth) {
        if (check()) {
            ret = depth;
            return true;
        }
        return false;
    }

    for (int j = row; j <= H; ++j) {
        for (int i = (j == row ? col : 1); i < N; ++i) {
            if (ladder[j][i]) continue;
            if (i > 1 && ladder[j][i - 1]) continue;
            if (i + 1 < N && ladder[j][i + 1]) continue;

            ladder[j][i] = true;
            if (dfs(max_depth, depth + 1, j, i)) return true;
            ladder[j][i] = false;
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
        if (dfs(i, 0, 1, 1)) {
            flag = true;
            break;
        }
    }

    cout << (flag ? ret : -1) << "\n";
    return 0;
}
