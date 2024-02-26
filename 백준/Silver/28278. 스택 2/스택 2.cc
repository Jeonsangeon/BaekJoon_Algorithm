#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int N, command, value;
    vector<int> s;
    cin >> N;
    for(int i = 0; i < N; ++i){
        scanf("%d", &command);
        if(command == 1){
            scanf("%d", &value);
            s.push_back(value);
        }
        else if(command == 2){
            if(s.empty()){
                printf("-1\n");
            } else{
                printf("%d\n", s.back());
                s.pop_back();
            }
        }
        else if(command == 3){
            printf("%zu\n", s.size());
        }
        else if(command == 4){
            printf("%d\n", s.empty());
        }
        else if(command == 5){
            if(s.empty()){
                printf("-1\n");
            } else{
                printf("%d\n", s.back());
            }
        }
    }

    return 0;
}