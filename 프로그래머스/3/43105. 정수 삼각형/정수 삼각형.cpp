#include <vector>
#include <algorithm>

using namespace std;

int N;

int solution(vector<vector<int>> triangle) {
    N = triangle.size();
    for(int i = 1; i < N; ++i) {
        for(int j = 0; j < triangle[i].size(); ++j) {
            if(j == 0) {
                triangle[i][j] += triangle[i-1][j];
            } else if(j == triangle[i].size()-1) {
                triangle[i][j] += triangle[i-1][j-1];
            } else {
                triangle[i][j] += max(triangle[i-1][j-1], triangle[i-1][j]);
            }
        }
    }
    
    return *max_element(triangle[N-1].begin(), triangle[N-1].end());
}