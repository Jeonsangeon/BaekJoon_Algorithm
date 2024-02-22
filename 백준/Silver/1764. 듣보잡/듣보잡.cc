#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(void)
{
    int n, m;
    string name;
    cin >> n >> m;
    set<string> name_set;
    set<string> name_list;
    for(int i = 0; i < n; ++i){
        cin >> name;
        name_set.insert(name);
    }
    for(int i = 0; i < m; ++i){
        cin >> name;
        auto iter = name_set.find(name);
        if(iter != name_set.end())
            name_list.insert(name);
    }
    cout << name_list.size() << endl;
    for(auto iter: name_list)
        cout << iter << endl;
        
    return 0;
}