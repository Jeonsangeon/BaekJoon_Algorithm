#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> S;
    vector<char> result;

    int N, tmp, cur = 1;
    cin >> N;
    while(N--){
        cin >> tmp;
        if(tmp < cur){
            if(S.top() == tmp){
                result.push_back('-'); S.pop();
            }
            else{
                cout << "NO\n";
                return 0;
            }
        }
        else{
            while(tmp >= cur){
                result.push_back('+'); S.push(cur++);
            }
            result.push_back('-'); S.pop();
        }
    }
    for(char s: result){
        cout << s << "\n";
    }

    return 0;
}