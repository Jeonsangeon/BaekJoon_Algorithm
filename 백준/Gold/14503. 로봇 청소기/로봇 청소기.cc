#include <iostream>
#include <array>

#define MAX_F 50

using namespace std;

int N, M, ret;
array<int, 3> cur;
int room[MAX_F][MAX_F];

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};


void work() {
    if(!room[cur[0]][cur[1]]) {
        room[cur[0]][cur[1]] = 2;
        ++ret;
    }

    array<int, 3> next;
    bool flag = false;
    for(int i = 1; i <= 4; ++i) {
        next[0] = cur[0] + dr[(cur[2]+4-i)%4];
        next[1] = cur[1] + dc[(cur[2]+4-i)%4];
        if(!room[next[0]][next[1]]) {
            cur[0] = next[0]; cur[1] = next[1];
            cur[2] = (cur[2]+4-i)%4;
            flag = true;
            break;
        }
    }

    if(!flag) {
        next[0] = cur[0] + dr[(cur[2]+2)%4];
        next[1] = cur[1] + dc[(cur[2]+2)%4];
        if(room[next[0]][next[1]] == 1)
            return;
        cur[0] = next[0];
        cur[1] = next[1];
    }

    work();
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    cin >> cur[0] >> cur[1] >> cur[2];
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            cin >> room[i][j];
        }
    }
    work();

    cout << ret << "\n";

    return 0;
}