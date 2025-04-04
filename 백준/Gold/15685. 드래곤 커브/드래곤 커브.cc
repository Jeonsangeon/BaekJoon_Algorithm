#include <iostream>
#include <array>
#include <vector>

#define MAX_F 101

using namespace std;

int N, r, c, dir, gen, ret;
bool field[MAX_F][MAX_F];

int dr[] = {0, -1, 0, 1};
int dc[] = {1, 0, -1, 0};

void checkRet() {
    for(int i = 0; i < 100; ++i) {
        for(int j = 0; j < 100; ++j) {
            if(field[i][j] && field[i][j+1] && field[i+1][j] && field[i+1][j+1])
                ++ret;
        }
    }
}

void dragonCurve() {
    vector<int> directions;
    directions.push_back(dir);
    int g = 0;
    while(g < gen) {
        for(int i = directions.size()-1; i >= 0; --i) {
            directions.push_back((directions[i]+1)%4);
        }
        ++g;
    }

    array<int, 2> loc = {r, c};
    field[loc[0]][loc[1]] = true;
    for(int d : directions) {
        loc[0] += dr[d]; loc[1] += dc[d];
        field[loc[0]][loc[1]] = true;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin >> c >> r >> dir >> gen;
        dragonCurve();
    }

    checkRet();
    cout << ret << "\n";

    return 0;
}