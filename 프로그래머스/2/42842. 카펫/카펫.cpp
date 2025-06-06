#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    if(yellow == 1)
        return {3, 3};
    
    for(int i = 1; i <= yellow / 2; ++i) {
        if((yellow % i) != 0)
            continue;
        if((i*2)+ (yellow/i)*2 == brown - 4) {
            return {(yellow/i)+2, i+2};
        }
    }
    
    return {-1, -1};
}