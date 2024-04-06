#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* DFS, MODUL */

void changeLocation(int& cur_row, int& cur_col, int direction){
    if(direction == 0)
        ++cur_col;
    else if(direction == 1)
        ++cur_row;
    else if(direction == 2)
        --cur_col;
    else if(direction == 3)
        --cur_row;
}

void checkDirection(vector<vector<int>> map, int cur_row, int cur_col, int& direction){
    if(direction == 0 && cur_col + 1 >= map[cur_row].size())
        direction = 2;
    else if(direction == 1 && cur_row + 1 >= map.size())
        direction = 3;
    else if(direction == 2 && cur_col - 1 < 0)
        direction = 0;
    else if(direction == 3 && cur_row - 1 < 0)
        direction = 1;
}

void moveDice(vector<int>& dice, int direction){
    // East
    if(direction == 0){
        swap(dice[3], dice[5]);
        swap(dice[4], dice[1]);
        swap(dice[4], dice[5]);
    }
    // South
    else if(direction == 1){
        for(int i = 3; i > 0; --i){
            swap(dice[i], dice[i-1]);
        }
    }
    // West
    else if(direction == 2){
        swap(dice[3], dice[4]);
        swap(dice[5], dice[1]);
        swap(dice[4], dice[5]);
    }
    // North
    else if(direction == 3){
        for(int i = 0; i < 3; ++i){
            swap(dice[i], dice[i+1]);
        }
    }
}

void getScore(vector<vector<int>>& map, int row, int col, int& score){
    int base = map[row][col];
    map[row][col] = 0;
    score += base;
    if(col+1 < map[row].size() && base == map[row][col+1])
        getScore(map, row, col+1, score);
    if(col-1 >= 0 && base == map[row][col-1])
        getScore(map, row, col-1, score);
    if(row+1 < map.size() && base == map[row+1][col])
        getScore(map, row+1, col, score);
    if(row-1 >= 0 && base == map[row-1][col])
        getScore(map, row-1, col, score);
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M, K, tmp;
    int total_score = 0;
    vector<int> dice = {2, 1, 5, 6, 4, 3};
    cin >> N >> M >> K;
    vector<vector<int>> map(N, vector<int>(M, 0)), tmp_map;

    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            cin >> tmp;
            map[i][j] = tmp;
        }
    }

    int cur_row = 0, cur_col = 0;
    int direction = 0;
    for(int i = 0; i < K; ++i){
        checkDirection(map, cur_row, cur_col, direction);
        changeLocation(cur_row, cur_col, direction);
        moveDice(dice, direction);
        tmp = 0;
        tmp_map = map;
        getScore(tmp_map, cur_row, cur_col, tmp);
        total_score += tmp;
        if(dice[3] > map[cur_row][cur_col])
            direction = (direction + 1) % 4;
        else if(dice[3] < map[cur_row][cur_col])
            direction = (4 + direction - 1) % 4;
    }
    
    cout << total_score << "\n";

    return 0;
}
