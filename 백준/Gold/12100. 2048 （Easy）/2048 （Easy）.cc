#include <iostream>
#include <array>
#include <algorithm>
#include <cstring>

#define MAX_N 20

using namespace std;

int N;
int initBoard[MAX_N][MAX_N];
int dx[] = {0, 1, 0, -1}; // 상, 우, 하, 좌
int dy[] = {-1, 0, 1, 0};

bool validate(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

void copyBoard(int src[MAX_N][MAX_N], int dest[MAX_N][MAX_N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            dest[i][j] = src[i][j];
        }
    }
}

void moveBlock(int dir, int board[MAX_N][MAX_N]) {
    bool merged[MAX_N][MAX_N] = {false};
    if (dir == 0 || dir == 3) { // 위쪽(0) 또는 왼쪽(3)
        for (int y = 0; y < N; ++y) {
            for (int x = 0; x < N; ++x) {
                if (board[y][x] == 0) continue;
                int nx = x, ny = y;
                while (validate(nx + dx[dir], ny + dy[dir]) && board[ny + dy[dir]][nx + dx[dir]] == 0) {
                    board[ny + dy[dir]][nx + dx[dir]] = board[ny][nx];
                    board[ny][nx] = 0;
                    nx += dx[dir];
                    ny += dy[dir];
                }
                if (validate(nx + dx[dir], ny + dy[dir]) && board[ny + dy[dir]][nx + dx[dir]] == board[ny][nx] && !merged[ny + dy[dir]][nx + dx[dir]]) {
                    board[ny + dy[dir]][nx + dx[dir]] *= 2;
                    board[ny][nx] = 0;
                    merged[ny + dy[dir]][nx + dx[dir]] = true;
                }
            }
        }
    } else { // 아래(2) 또는 오른쪽(1)
        for (int y = N - 1; y >= 0; --y) {
            for (int x = N - 1; x >= 0; --x) {
                if (board[y][x] == 0) continue;
                int nx = x, ny = y;
                while (validate(nx + dx[dir], ny + dy[dir]) && board[ny + dy[dir]][nx + dx[dir]] == 0) {
                    board[ny + dy[dir]][nx + dx[dir]] = board[ny][nx];
                    board[ny][nx] = 0;
                    nx += dx[dir];
                    ny += dy[dir];
                }
                if (validate(nx + dx[dir], ny + dy[dir]) && board[ny + dy[dir]][nx + dx[dir]] == board[ny][nx] && !merged[ny + dy[dir]][nx + dx[dir]]) {
                    board[ny + dy[dir]][nx + dx[dir]] *= 2;
                    board[ny][nx] = 0;
                    merged[ny + dy[dir]][nx + dx[dir]] = true;
                }
            }
        }
    }
}

int getMaxBlock(int board[MAX_N][MAX_N]) {
    int maxVal = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            maxVal = max(maxVal, board[i][j]);
        }
    }
    return maxVal;
}

int dfs(int depth, int board[MAX_N][MAX_N]) {
    if (depth == 5) return getMaxBlock(board);
    int maxVal = 0;
    for (int dir = 0; dir < 4; ++dir) {
        int newBoard[MAX_N][MAX_N];
        copyBoard(board, newBoard);
        moveBlock(dir, newBoard);
        maxVal = max(maxVal, dfs(depth + 1, newBoard));
    }
    return maxVal;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> initBoard[i][j];
        }
    }
    cout << dfs(0, initBoard) << "\n";
    return 0;
}
