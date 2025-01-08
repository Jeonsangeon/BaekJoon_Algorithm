#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> split(string input, string deli) {
    vector<string> result;
    long long pos = 0;
    string token = "";
    while((pos = input.find(deli)) != string::npos){
        token = input.substr(0, pos);
        result.push_back(token);
        input.erase(0, pos + deli.length());
    }
    result.push_back(input);
    
    return result;
}

string solution(string s) {
    vector<string> items = split(s, " ");
    string answer = "";
    
    for(string item : items){
        item[0] = toupper(item[0]);
        for(int i = 1; i < item.length(); ++i){
            item[i] = tolower(item[i]);
        }
        answer += (item + " ");
    }
    answer.pop_back();
      
    return answer;
}