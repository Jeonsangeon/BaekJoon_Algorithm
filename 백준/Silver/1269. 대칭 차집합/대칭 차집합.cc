#include <iostream>
#include <set>
using namespace std;

int main(void)
{
    set<int> s;
    int n, m, num;
    cin >> n >> m;

    for(int i = 0; i < n; ++i){
        cin >> num;
        s.insert(num);
    }

    int inter = 0;
    for(int i = 0; i < m; ++i){
        cin >> num;
        if(s.find(num) != s.end())
            ++inter;
    }
    cout << (n+m-2*inter);
}