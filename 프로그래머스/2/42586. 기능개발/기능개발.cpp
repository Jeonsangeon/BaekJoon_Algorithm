#include <string>
#include <vector>
#include <cmath>
#include <deque>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    deque<int> days;
    for(int i = 0; i < progresses.size(); ++i){
        int rest = 100 - progresses[i];
        int day = ceil(rest / ((double)speeds[i]));
        days.push_back(day);
    }
    
    int required_day = days[0];
    int build = 1;
    for(int i = 1; i < days.size(); ++i){
        if(required_day >= days[i]){
            ++build;
        } else{
            answer.push_back(build);
            required_day = days[i];
            build = 1;
        }
        if(i == days.size()-1)
            answer.push_back(build);
    }
    
    return answer;
}