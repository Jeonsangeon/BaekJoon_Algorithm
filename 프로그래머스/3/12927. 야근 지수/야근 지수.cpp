#include <iostream>;
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

bool compare(int a, int b) {return b < a;}

long long solution(int n, vector<int> works) {
    long long ret = 0;
    sort(works.begin(), works.end(), compare);
    
    int base;
    while(n > 0) {
        base = works[0];
        
        if(!base)
            break;
        
        for(int i = 0; i < works.size(); ++i) {
            if(base != works[i] || n <= 0)
                break;
            --works[i];
            --n;
        }
    }
    
    for(int work : works) {
        ret += (work * work);
    }
    
    return ret;
}