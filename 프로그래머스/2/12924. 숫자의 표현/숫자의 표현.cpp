#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0, tmp;
    for(int cur = 1; cur <= n; ++cur) {
        tmp = n;
        for(int i = cur; tmp > 0; ++i){
            tmp -= i;
            if(tmp == 0)
                ++answer;
        }
    }
    
    return answer;
}