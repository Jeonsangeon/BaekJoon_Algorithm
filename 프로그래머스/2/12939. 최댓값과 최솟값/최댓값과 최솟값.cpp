#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> split(string input, string delimiter) {
    vector<string> result;
    long long pos = 0;
    string token = "";
    while((pos = input.find(delimiter)) != string::npos){
        token = input.substr(0, pos);
        result.push_back(token);
        input.erase(0, pos + delimiter.length());
    }
    result.push_back(input);
    
    return result;
}

string solution(string s) {
    vector<string> input = split(s, " ");
    vector<int> conver;
    for(string c : input){
        conver.push_back(stoi(c));
    }
    sort(conver.begin(), conver.end());
    
    string answer = to_string(conver.front()) + " " + to_string(conver.back());
    return answer;
}