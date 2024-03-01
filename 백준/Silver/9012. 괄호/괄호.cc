#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void)
{
    int T;
    cin >> T;
    for(int i = 0; i < T; ++i){
        string tmp;
        stack<char> s;
        cin >> tmp;
        int complete = 1;
        for(int j = 0; j < tmp.length(); ++j){
            if(tmp[j] == '(')
                s.push('(');
            else if(tmp[j] == ')'){
                if(s.empty()){
                    complete = 0;
                    break;
                }
                else{
                    s.pop();
                }
            }
        }
        if(complete && s.empty()){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }

    return 0;
}