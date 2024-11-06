#include <iostream>
#include <queue>

using namespace std;

int field[100001] = {0};
bool visit[100001];

int dx[] = {-1, 1};
int n, k;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    queue<int> Q;
    Q.push(n);    
    visit[n] = 1;
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        if(cur == k){
            cout << field[cur] << "\n";
            return 0;
        }
        for(int dir = 0; dir < 3; ++dir){
            int nx;
            if(dir == 2){
                nx = 2 * cur;
            }
            else{
                nx = cur + dx[dir];
            }
            if(nx < 0 || nx > 100001)
                continue;
            if(visit[nx])
                continue;
            field[nx] = field[cur] + 1;
            Q.push(nx);
            visit[nx] = 1;
        }
    }

    return 0;
}