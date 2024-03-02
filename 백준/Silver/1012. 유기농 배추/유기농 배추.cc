#include <iostream>
#include <vector>
using namespace std;

void check_field(vector<vector<bool>> *field, int row, int col, int M, int N){
    (*field)[row][col] = false;
    if(row > 0 && (*field)[row-1][col])
        check_field(field, row-1, col, M, N);
    if(row < N-1 && (*field)[row+1][col])
        check_field(field, row+1, col, M, N);
    if(col > 0 && (*field)[row][col-1])
        check_field(field, row, col-1, M, N);
    if(col < M-1 && (*field)[row][col+1])
        check_field(field, row, col+1, M, N);
}

int main(void)
{
    int T, M, N, K, x, y;
    scanf("%d", &T);
    for(int i = 0; i < T; ++i){
        scanf("%d %d %d", &M, &N, &K);
        vector<vector<bool>> field;
        int count = 0;
        for(int j = 0; j < N; ++j){
            vector<bool> temp(M, false);
            field.push_back(temp);
        }
        for(int j = 0; j < K; ++j){
            scanf("%d %d", &x, &y);
            field[y][x] = true;
        }
        for(int row = 0; row < N; ++row){
            for(int col = 0; col < M; ++col){
                if(field[row][col]){
                    count++;
                    check_field(&field, row, col, M, N);
                }
            }
        }
        cout << count << endl;
    }

    return 0;
}