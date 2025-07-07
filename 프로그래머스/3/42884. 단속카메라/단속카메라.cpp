#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

int ret = 1;

bool compare(vector<int> a, vector<int> b) {
    if(a[0] == b[0])
        return a[1] < b[1];
    
    return a[0] < b[0];
}

int solution(vector<vector<int>> routes) {
    sort(routes.begin(), routes.end(), compare);
    
    int cur = routes[0][1];
    for(int i = 1; i < routes.size(); ++i) {
       if(cur < routes[i][0]) {

           cur = routes[i][1];
           ++ret;
       } else {
           if(routes[i][1] < cur)
               cur = routes[i][1];
       }
    }

    return ret;
}