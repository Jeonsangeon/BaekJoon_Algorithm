#include <iostream>
#include <array>

#define MAX_N 21

using namespace std;

int N, ret;
int field[MAX_N][MAX_N], order[MAX_N * MAX_N];
bool like[MAX_N * MAX_N][MAX_N * MAX_N];

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

bool validate(int r, int c) {
    return r > 0 && r <= N && c > 0 && c <= N;
}

array<int, 2> check_sub(int cur, int r, int c) {
    int like_num = 0, empty_num = 0;
    for(int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(!validate(nr, nc))
            continue;
        if(!field[nr][nc])
            ++empty_num;
        else if(like[cur][field[nr][nc]])
            ++like_num;
    }

    return {like_num, empty_num};
}

void check_loc(int cur) {
    array<int, 2> candi_loc;
    int max_like = -1, max_empty = -1;
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            if(field[i][j])
                continue;
            array<int, 2> cur_d = check_sub(cur, i, j);
            if(cur_d[0] > max_like) {
                candi_loc = {i, j};
                max_like = cur_d[0];
                max_empty = cur_d[1];
            } else if(cur_d[0] == max_like && cur_d[1] > max_empty) {
                candi_loc = {i, j};
                max_like = cur_d[0];
                max_empty = cur_d[1];
            }
        }
    }

    field[candi_loc[0]][candi_loc[1]] = cur;
}

void calculate_ret() {
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            array<int, 2> cur_d = check_sub(field[i][j], i, j);
            if(cur_d[0] == 1)
                ret += 1;
            else if(cur_d[0] == 2)
                ret += 10;
            else if(cur_d[0] == 3)
                ret += 100;
            else if(cur_d[0] == 4)
                ret += 1000;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int tmp;
    for(int i = 0; i < N * N; ++i) {
        cin >> order[i];
        for(int j = 0; j < 4; ++j) {
            cin >> tmp;
            like[order[i]][tmp] = true;
        }
    }

    for(int i = 0; i < N * N; ++i) {
        check_loc(order[i]);
    }

    calculate_ret();

    cout << ret << "\n";

    return 0;
}