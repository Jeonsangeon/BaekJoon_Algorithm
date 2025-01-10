#include <string>
#include <vector>

#define MAX_NUM 100000

using namespace std;

int fibo[MAX_NUM];

int solution(int n) {
    fibo[0] = 0; fibo[1] = 1;
    for(int i = 2; i <= n; ++i)
        fibo[i] = (fibo[i-1] + fibo[i-2]) % 1234567;
    return fibo[n];
}