#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int K, N;
    vector<int> s;
    scanf("%d", &K);
    for(int i = 0; i < K; ++i){
        scanf("%d", &N);
        if(N == 0)
            s.pop_back();
        else
            s.push_back(N);
    }
    int sum = 0;
    for(int i = 0; i < s.size(); ++i){
        sum += s[i];
    }
    printf("%d\n", sum);

    return 0;
}