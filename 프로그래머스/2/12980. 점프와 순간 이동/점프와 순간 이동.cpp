#include <iostream>

using namespace std;

int solution(int n) {
    int ret = 0;
    while(n > 0) {
        if(n % 2 == 0)
             n /= 2;
        else {
            --n;
            ++ret;
        }
    }

    return ret;
}