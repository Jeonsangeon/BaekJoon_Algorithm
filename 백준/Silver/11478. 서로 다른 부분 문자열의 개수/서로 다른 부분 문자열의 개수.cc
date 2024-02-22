#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(void)
{
    string s;
    cin >> s;
    set<string> string_set;
    for(int i = 0; i < s.length(); ++i){
        for(int j = 1; j <= s.length() - i; ++j){
            string_set.insert(s.substr(i, j));
        }
    }
    cout << string_set.size() << endl;
    return 0;
}