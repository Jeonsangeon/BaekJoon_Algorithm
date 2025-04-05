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
vector<array<int, 2>> chicken;
vector<bool> chicken_open;
vector<vector<int>> dist;

void calculateDist() {
    int H = houses.size();
    int C = chicken.size();
    dist.resize(H, vector<int>(C));
    for(int i = 0; i < H; ++i) {
        for(int j = 0; j < C; ++j) {
            dist[i][j] = abs(houses[i][0] - chicken[j][0]) + abs(houses[i][1] - chicken[j][1]);
        }
    }
}

int calculateMinDist(int idx) {
    int min_dist = INF;
    for(int i = 0; i < (int)chicken.size(); ++i) {
        if(chicken_open[i])
            min_dist = min(min_dist, dist[idx][i]);
    }
    return min_dist;
}

void dfs(int count, int idx) {
    if(count == M) {
        int city_dist = 0;
        for(int i = 0; i < (int)houses.size(); ++i)
            city_dist += calculateMinDist(i);
        ret = min(ret, city_dist);
        return;
    }

    for(int i = idx; i < (int)chicken.size(); ++i) {
        if(!chicken_open[i]) {
            chicken_open[i] = true;
            dfs(count+1, i+1);
            chicken_open[i] = false;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cin >> city[i][j];
            if(city[i][j] == 1) {
                houses.push_back({i, j});
            }
            else if(city[i][j] == 2) {
                chicken.push_back({i, j});
            }
        }
    }

    chicken_open.resize(chicken.size(), false);
    calculateDist();
    dfs(0, 0);

    cout << ret << "\n";

    return 0;
}