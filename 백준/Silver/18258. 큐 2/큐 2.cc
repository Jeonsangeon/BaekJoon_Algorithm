#include <iostream>
#include <deque>
#include <string>

using namespace std;

int control_queue(deque<int>* dq, string command)
{
    if(command == "size")
        return dq->size();
    if(command == "empty"){
        if(dq->empty())
            return 1;
        else
            return 0;
    }
    if(dq->empty())
        return -1;
    else{
        if(command == "pop"){
            int value = dq->front();
            dq->pop_front();
            return value;
        }
        if(command == "front")
            return dq->front();
        if(command == "back")
            return dq->back();
    }
    
    return -1;
}

int main(void)
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    int N, value;
    string command;
    deque<int> dq;
    cin >> N;
    for(int i = 0; i < N; ++i){
        cin >> command;
        if(command == "push"){
            cin >> value;
            dq.push_back(value);
        } else{
            cout << control_queue(&dq, command) << "\n";
        }
    }
}