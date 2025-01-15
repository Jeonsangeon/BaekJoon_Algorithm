#include <iostream>
#include <utility>
#define L_SIZE 100
#define X first
#define Y second

using namespace std;

int ladder[L_SIZE][L_SIZE];
bool check;

void dfs(bool visited[L_SIZE][L_SIZE], pair<int, int> cur) {
    if (ladder[cur.Y][cur.X] == 2) {
        check = true;
        return;
    }
    visited[cur.Y][cur.X] = true;
    if (cur.X - 1 >= 0 && ladder[cur.Y][cur.X - 1] && !visited[cur.Y][cur.X - 1])
        dfs(visited, make_pair(cur.X - 1, cur.Y));
    else if (cur.X + 1 < L_SIZE && ladder[cur.Y][cur.X + 1] && !visited[cur.Y][cur.X + 1])
        dfs(visited, make_pair(cur.X + 1, cur.Y));
    else if (cur.Y + 1 < L_SIZE && ladder[cur.Y + 1][cur.X] && !visited[cur.Y + 1][cur.X])
        dfs(visited, make_pair(cur.X, cur.Y + 1));
}

int main(int argc, char **argv) {
	ios::sync_with_stdio(0);
    cin.tie(0);
    int tmp;
    for (int test_case = 1; test_case <= 10; ++test_case) {
        cin >> tmp;
        check = false;

        for (int i = 0; i < L_SIZE; ++i)
            for (int j = 0; j < L_SIZE; ++j)
                cin >> ladder[i][j];

        int start_x;
        for (start_x = 0; start_x < L_SIZE; ++start_x) {
            if (ladder[0][start_x]) {
                bool visited[L_SIZE][L_SIZE] = {false};
                dfs(visited, make_pair(start_x, 0));
                if (check)
                    break;
            }
        }
        cout << "#" << test_case << " " << start_x << "\n";
    }
    return 0;
}
