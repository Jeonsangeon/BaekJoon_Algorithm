#include <iostream>
#include <string>
#include <vector>

#define MAX_N 101
#define MOD 1000000007

using namespace std;

int field[MAX_N][MAX_N];

int solution(int m, int n, vector<vector<int>> puddles) {
    field[1][1] = 1;
    for(vector<int> puddle : puddles)
        field[puddle[1]][puddle[0]] = -1;
    for(int r = 1; r <= n; ++r) {
        for(int c = 1; c <= m; ++c) {
            if(field[r][c] == -1)
                continue;
            if(field[r-1][c] != -1)
                field[r][c] += field[r-1][c];
            if(field[r][c-1] != -1)
                field[r][c] += field[r][c-1];
            field[r][c] %= MOD;
        }
    }
    
    return field[n][m];
}