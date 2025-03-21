#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_S 500

int N, M;
int field[MAX_S][MAX_S];
bool visited[MAX_S][MAX_S] = { false };
int ret = 0;
int max_val = 0;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void dfs(int r, int c, int depth, int sum) {
    if(sum + (4 - depth) * max_val <= ret) return;

    if (depth == 4) {
        ret = max(ret, sum);
        return;
    }
    for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i], nc = c + dc[i];
        if (nr >= 0 && nr < N && nc >= 0 && nc < M && !visited[nr][nc]) {
            visited[nr][nc] = true;
            dfs(nr, nc, depth + 1, sum + field[nr][nc]);
            visited[nr][nc] = false;
        }
    }
}

void checkTShape(int r, int c) {
    int sum = field[r][c];
    if (r - 1 >= 0 && c - 1 >= 0 && c + 1 < M)
        ret = max(ret, sum + field[r-1][c] + field[r][c-1] + field[r][c+1]);
    if (r + 1 < N && c - 1 >= 0 && c + 1 < M)
        ret = max(ret, sum + field[r+1][c] + field[r][c-1] + field[r][c+1]);
    if (c - 1 >= 0 && r - 1 >= 0 && r + 1 < N)
        ret = max(ret, sum + field[r][c-1] + field[r-1][c] + field[r+1][c]);
    if (c + 1 < M && r - 1 >= 0 && r + 1 < N)
        ret = max(ret, sum + field[r][c+1] + field[r-1][c] + field[r+1][c]);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("sample_input.txt", "r", stdin);

    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> field[i][j];
            max_val = max(max_val, field[i][j]);
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            visited[i][j] = true;
            dfs(i, j, 1, field[i][j]);
            visited[i][j] = false;
            checkTShape(i, j);
        }
    }
    
    cout << ret << "\n";
    return 0;
}
