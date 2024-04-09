#include <iostream>
#include <algorithm>
#include <string>
#include <climits>

using namespace std;

/* DFS */

int N, max_value;
string formula;

int calculation(int a, int b, char op)
{
    int result = a;
    if(op == '+')
        result += b;
    else if(op == '-')
        result -= b;
    else if(op == '*')
        result *= b;
    return result;
}

void DFS(int index, int current_value)
{
    if(index > N - 1){
        max_value = max(max_value, current_value);
        return;
    }
    // 이전 Operater설정
    char op = (index == 0) ? '+' : formula[index-1];

    //괄호O
    if(index + 2 < N){
        int bound = calculation(formula[index] - '0', formula[index+2] - '0', formula[index+1]);
        DFS(index+4, calculation(current_value, bound, op));
    }
    //괄호X
    DFS(index+2, calculation(current_value, formula[index] - '0', op));
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    cin >> formula;
    max_value = INT_MIN;
    DFS(0, 0);
    cout << max_value << "\n";

    return 0;
}
