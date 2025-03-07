#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void swap(vector<int>& arr) {
    int tmp = arr[0];
    arr[0] = arr[1];
    arr[1] = tmp;
}

int solution(vector<vector<int>> sizes) {
    int max_w = -1;
    int max_l = -1;
    for(vector<int> v : sizes) {
        if(v[0] < v[1])
            swap(v);
        max_w = max(max_w, v[0]);
        max_l = max(max_l, v[1]);
    }
    return max_w * max_l;
}