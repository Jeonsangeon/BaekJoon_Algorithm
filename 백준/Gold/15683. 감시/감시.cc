#include <iostream>
#include <algorithm>
#include <array>
#include <vector>

#define MAX_R 8

using namespace std;

int N, M, ret = 100;
int room[MAX_R][MAX_R];
vector<array<int, 3>> cctvs;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

bool validation(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < M;
}

int checkRoom(int arr[MAX_R][MAX_R]) {
    int num = 0;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            if(!arr[i][j])
                ++num;
        }
    }
    return num;
}

void copyArr(int src[MAX_R][MAX_R], int dst[MAX_R][MAX_R]) {
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j)
            dst[i][j] = src[i][j];
}

void watch(int arr[MAX_R][MAX_R], array<int, 2> loc, int dir) {
    while(validation(loc[0], loc[1]) && arr[loc[0]][loc[1]] != 6) {
        if(!arr[loc[0]][loc[1]])
            arr[loc[0]][loc[1]] = 7;
        loc[0] += dr[dir]; loc[1] += dc[dir];
    }
}

void dfs(int arr[MAX_R][MAX_R], int cctv_num) {
    if(cctv_num == cctvs.size()) {
        
        ret = min(ret, checkRoom(arr));
        return;
    }
    int tmp[MAX_R][MAX_R];
    array<int, 3> cctv = cctvs[cctv_num];
    if(cctv[0] == 1) {
        for(int i = 0; i < 4; ++i) {
            copyArr(arr, tmp);
            watch(tmp, {cctv[1], cctv[2]}, i);
            dfs(tmp, cctv_num+1);
        }
    }
    else if(cctv[0] == 2) {
        for(int i = 0; i < 2; ++i) {
            copyArr(arr, tmp);
            watch(tmp, {cctv[1], cctv[2]}, i);
            watch(tmp, {cctv[1], cctv[2]}, i+2);
            dfs(tmp, cctv_num+1);
        }
    }
    else if(cctv[0] == 3) {
        for(int i = 0; i < 4; ++i) {
            copyArr(arr, tmp);
            watch(tmp, {cctv[1], cctv[2]}, i);
            watch(tmp, {cctv[1], cctv[2]}, (i+1)%4);
            dfs(tmp, cctv_num+1);
        }
    }
    else if(cctv[0] == 4) {
        for(int i = 0; i < 4; ++i) {
            copyArr(arr, tmp);
            watch(tmp, {cctv[1], cctv[2]}, (i+3)%4);
            watch(tmp, {cctv[1], cctv[2]}, i);
            watch(tmp, {cctv[1], cctv[2]}, (i+1)%4);
            dfs(tmp, cctv_num+1);
        }
    }
    else if(cctv[0] == 5) {
        for(int i = 0; i < 4; ++i)
            watch(arr, {cctv[1], cctv[2]}, i);
        dfs(arr, cctv_num+1);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            cin >> room[i][j];
            if(room[i][j] && room[i][j] != 6)
                cctvs.push_back({room[i][j], i, j});
        }
    }

    dfs(room, 0);
    cout << ret << "\n";

    return 0;
}