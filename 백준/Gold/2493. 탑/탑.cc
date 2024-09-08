#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    pair<int, int> tower;
    stack<pair<int, int>> towers;
    vector<int> ans;

    int N, tmp;
    cin >> N;

    for(int i = 1; i <= N; ++i){
        cin >> tmp;
        tower.first = tmp; tower.second = i;

        while(!towers.empty() && towers.top().first < tmp)
            towers.pop();

        if(towers.empty()){
            ans.push_back(0);
            towers.push(tower);
        }
        else{
            ans.push_back(towers.top().second);
            towers.push(tower);
        }
    }

    for(int e : ans)
        cout << e << " ";

    return 0;
}