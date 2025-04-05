#include <iostream>
#include <vector>
#include <array>
#include <cstdlib>
#include <algorithm>

#define MAX_N 50
#define INF 0x3fffffff

using namespace std;

int N, M, ret = INF;
int city[MAX_N][MAX_N];

vector<array<int, 2>> houses;
vector<array<int, 2>> chickens;
vector<vector<int>> dist;
vector<bool> chicken_open;

void calculateDist() {
    int H = houses.size();
    int C = chickens.size();
    dist.resize(H, vector<int>(C));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < C; ++j) {
            dist[i][j] = abs(houses[i][0] - chickens[j][0]) + abs(houses[i][1] - chickens[j][1]);
        }
    }
}

int calculateCityDistance() {
    int total = 0;
    for (int i = 0; i < (int)houses.size(); ++i) {
        int min_dist = INF;
        for (int j = 0; j < (int)chickens.size(); ++j) {
            if (chicken_open[j]) {
                min_dist = min(min_dist, dist[i][j]);
            }
        }
        total += min_dist;
    }
    return total;
}

void dfs(int selected, int idx) {
    if (selected == M) {
        ret = min(ret, calculateCityDistance());
        return;
    }

    for (int i = idx; i < (int)chickens.size(); ++i) {
        if (!chicken_open[i]) {
            chicken_open[i] = true;
            dfs(selected + 1, i + 1);
            chicken_open[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> city[i][j];
            if (city[i][j] == 1)
                houses.push_back({i, j});
            else if (city[i][j] == 2)
                chickens.push_back({i, j});
        }
    }

    chicken_open.resize(chickens.size(), false);
    calculateDist();
    dfs(0, 0);

    cout << ret << '\n';
    return 0;
}
