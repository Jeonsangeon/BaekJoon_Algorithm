#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int removeZero(string& s) {
    int cnt = 0;
    for(int i = 0; i < s.size();) {
        if(s[i] == '0'){
            s.erase(s.begin()+i);
            ++cnt;
        }
        else
            ++i;
    }
    return cnt;
}

string toBinary(int num) {
    string result;
    while(num != 1) {
        result.push_back((num % 2) + '0');
        num /= 2;
    }
    result.push_back('1');
    reverse(result.begin(), result.end());

    return result;
}

vector<int> solution(string s) {
    vector<int> answer = {0, 0};
    while(s != "1") {
        answer[1] += removeZero(s);
        s = toBinary(s.size());
        ++answer[0];
    }
    
    return answer;
}