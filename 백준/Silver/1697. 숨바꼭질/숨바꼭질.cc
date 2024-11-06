#include <iostream>
#include <queue>

using namespace std;

int field[100002] = {0};  // 배열 범위를 100001까지 확장
bool visit[100002];       // 방문 배열도 100001까지 확장

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
        
        for(int dir = 0; dir < 2; ++dir){
            int nx = cur + dx[dir];
            if(nx < 0 || nx > 100001) // 경계 조건을 100001로 변경
                continue;
            if(visit[nx])
                continue;
            field[nx] = field[cur] + 1;
            Q.push(nx);
            visit[nx] = 1;
        }
        
        int nx = 2 * cur;
        if(nx >= 0 && nx <= 100001 && !visit[nx]){  // 경계 조건을 100001로 변경
            field[nx] = field[cur] + 1;
            Q.push(nx);
            visit[nx] = 1;
        }
    }

    return 0;
}
