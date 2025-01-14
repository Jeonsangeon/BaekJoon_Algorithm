#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 100
#define AVAILABLE_COUNT 10001

using namespace std;

int N;
int score[MAX_N];
bool available[AVAILABLE_COUNT];

int main(int argc, char** argv)
{
    int test_case, T;
    cin >> T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N;
        for(int i = 0; i < N; ++i)
            cin >> score[i];
        
        fill(available, available + AVAILABLE_COUNT, false);
        available[0] = true;
        int max_sum = 0;
        
        for(int i = 0; i < N; ++i) {
            for(int j = max_sum; j >= 0; --j) {
                if(available[j]) {
                    available[j + score[i]] = true;
                }
            }
            max_sum += score[i];
        }
        
        int answer = 0;
        for(int i = 0; i <= max_sum; ++i) {
            if(available[i]) ++answer;
        }
        
        cout << "#" << test_case << ' ' << answer << "\n";
    }

    return 0;
}
