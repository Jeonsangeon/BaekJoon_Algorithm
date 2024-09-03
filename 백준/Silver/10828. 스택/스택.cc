#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> S;
    string op;
    int N, tmp;

    cin >> N;
    while(N--){
        cin >> op;
        if(op == "push"){
            cin >> tmp;
            S.push(tmp);
        }
        else if(op == "size")
            cout << S.size() << "\n";
        else if(op == "empty")
            cout << S.empty() << "\n";
        else{
            if(S.empty())
                cout << -1 << "\n";
            else{
                if(op == "top")
                    cout << S.top() << "\n";
                else{
                    cout << S.top() << "\n";
                    S.pop();
                }
            }
        }
    }

    return 0;
}