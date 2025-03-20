#include <iostream>
#include <array>
#include <queue>

#define MAX_N 102
#define MAX_K 100

using namespace std;

int N, K, L;
int field[MAX_N][MAX_N];
pair<int, char> turn[MAX_K];

int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

int cur_dir = 0, turn_index = 0, cur_time = 0;
array<int, 2> cur = {1, 1};
queue<array<int, 2>> tail;

bool validate(int r, int c) {
    return r > 0 && r <= N && c > 0 && c <= N;
}

bool moveSnack() {
    ++cur_time;
    array<int, 2> next = {cur[0] + dr[cur_dir] , cur[1] + dc[cur_dir]};
    if(!validate(next[0], next[1]) || field[next[0]][next[1]] == 1)
        return false;

    if(!field[next[0]][next[1]]) {
        field[tail.front()[0]][tail.front()[1]] = 0;
        tail.pop();
    }

    field[next[0]][next[1]] = 1;
    cur[0] = next[0]; cur[1] = next[1];
    tail.push({next[0], next[1]});

    return true;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    field[1][1] = 1;
    tail.push({1, 1});
    int r, c, x;
    char d;
    for(int i = 0; i < K; ++i) {
        cin >> r >> c;
        field[r][c] = 2;
    }
    cin >> L;
    for(int i = 0; i < L; ++i)
        cin >> turn[i].first >> turn[i].second;

    while(moveSnack()) {
        if(turn_index < L && cur_time == turn[turn_index].first) {
            if(turn[turn_index].second == 'L')
                cur_dir = (cur_dir + 3) % 4;
            else if (turn[turn_index].second == 'D')
                cur_dir = (cur_dir + 1) % 4;
            ++turn_index;
        }
    }

    cout << cur_time << "\n";

    return 0;
}