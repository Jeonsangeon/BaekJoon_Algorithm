#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main(void)
{
    int N, temp, M, q_count = 0;
    vector<int> q;
    vector<int> qs;
    cin >> N;
    for(int i = 0; i < N; ++i){
        cin >> temp;
        qs.push_back(temp);
    }
    for(int i = 0; i < N; ++i){
        cin >> temp;
        if(qs[i] == 0){
            q.push_back(temp);
            ++q_count;
        }
    }
    reverse(q.begin(), q.end());

    cin >> M;
    for(int i = 0; i < M; ++i){
        cin >> temp;
        q.push_back(temp);
    }

    for(int i = 0; i < M; ++i){
        if(i == M -1)
            cout << q[i] << endl;
        else
            cout << q[i] << " ";
    }

    return 0;
}