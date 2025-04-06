#include <iostream>
#include <vector>
#include <deque>

#define MAX_N 11

using namespace std;

int N, M, K;
int A[MAX_N][MAX_N];
int field[MAX_N][MAX_N];
deque<int> trees[MAX_N][MAX_N];
vector<int> dead[MAX_N][MAX_N];

const int dx[8] = {-1,-1,-1,0,0,1,1,1};
const int dy[8] = {-1,0,1,-1,1,-1,0,1};

bool validate(int r, int c) {
    return r >= 1 && r <= N && c >= 1 && c <= N;
}

void spring() {
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j) {
            deque<int> new_trees;
            for (int k = 0; k < trees[i][j].size(); ++k) {
                int age = trees[i][j][k];
                if (field[i][j] >= age) {
                    field[i][j] -= age;
                    new_trees.push_back(age + 1);
                } else {
                    dead[i][j].push_back(age);
                }
            }
            trees[i][j] = new_trees;
        }
}

void summer() {
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j) {
            for (int age : dead[i][j])
                field[i][j] += age / 2;
            dead[i][j].clear();
        }
}

void fall() {
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j) {
            for (int age : trees[i][j]) {
                if (age % 5 == 0) {
                    for (int d = 0; d < 8; ++d) {
                        int ni = i + dx[d];
                        int nj = j + dy[d];
                        if (validate(ni, nj)) {
                            trees[ni][nj].push_front(1);
                        }
                    }
                }
            }
        }
}

void winter() {
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            field[i][j] += A[i][j];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j) {
            cin >> A[i][j];
            field[i][j] = 5;
        }

    for (int i = 0; i < M; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        trees[x][y].push_back(z);
    }

    while (K--) {
        spring();
        summer();
        fall();
        winter();
    }

    int result = 0;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            result += trees[i][j].size();

    cout << result << "\n";
    return 0;
}
