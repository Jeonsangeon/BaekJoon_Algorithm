#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void)
{
    while(true){
        string sentence;
        stack<char> s;
        getline(cin, sentence, '\n');
        if(sentence[0] == '.')
            break;
        bool complete = true;
        for(int i = 0; i < sentence.length(); ++i){
            if(sentence[i] == '(' || sentence[i] == '['){
                s.push(sentence[i]);
            }
            else if(sentence[i] == ')' || sentence[i] == ']'){
                if(s.empty()){
                    complete = false;
                    break;
                }
                else{
                    if(sentence[i] == ')'){
                        if (s.top() != '('){
                            complete = false;
                            break;
                        } else{
                            s.pop();
                        }
                    } else{
                        if (s.top() != '['){
                            complete = false;
                            break;
                        } else{
                            s.pop();
                        }
                    }
                }
            }
        }
        if(complete && s.empty()){
            cout << "yes" << endl;
        } else{
            cout << "no" << endl;
        }
    }

    return 0;
}