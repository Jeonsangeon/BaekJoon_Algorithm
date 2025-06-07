#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> operations) {
    multiset<int> ms;

    for(string op : operations) {
        stringstream ss(op);
        string cmd;
        int num;
        
        ss >> cmd >> num;

        if(cmd == "I") {
            ms.insert(num);
        } else if(!ms.empty()) {
            if(num == 1) {
                auto it = prev(ms.end());
                ms.erase(it);
            } else if(num == -1) {
                auto it = ms.begin();
                ms.erase(it);
            }
        }
    }

    if(ms.empty())
        return {0, 0};

    return {*prev(ms.end()), *ms.begin()};
}
