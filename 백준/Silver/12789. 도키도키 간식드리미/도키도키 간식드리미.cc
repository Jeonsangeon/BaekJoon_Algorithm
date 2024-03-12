#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    int N, num;
    stack<int> st;
    cin >> N;
    int order = 1;
    for(int i = 0; i < N; ++i){
        cin >> num;
        while((!st.empty()) && (st.top() == order)){
            st.pop();
            order++;
        }
        if(num == order){
            ++order;
        } else{
            st.push(num);
        }
    }
    while((!st.empty()) && (st.top() == order)){
        st.pop();
        order++;
    }
    if(st.empty())
        cout << "Nice" << "\n";
    else
        cout << "Sad" << "\n";

    return 0;
}