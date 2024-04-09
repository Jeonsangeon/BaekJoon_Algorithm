#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/* BFS */

const int dr[] = {1, -1, 0, 0};
const int dc[] = {0, 0, 1, -1};

struct INFO
{
    int Rr, Rc;
    int Br, Bc;
    int round;
}start;

int solve(vector<string> board){
    queue<INFO> q;
    q.push(start);
    bool visited[10][10][10][10] = {false};

    while(!q.empty()){
        INFO cur = q.front(); q.pop();
        visited[cur.Rr][cur.Rc][cur.Br][cur.Bc] = true;
        // 10번 초과로 움직이는 경우
        if(cur.round > 10)
            break;
        // 빨간 구슬은 구멍에 들어가고, 파란 구슬은 구멍에 들어가지 않은 경우
        if(board[cur.Rr][cur.Rc] == 'O' && board[cur.Br][cur.Bc] != 'O')
            return cur.round;
        
        for(int i = 0; i < 4; ++i){
            int next_Rr = cur.Rr;
            int next_Rc = cur.Rc;
            int next_Br = cur.Br;
            int next_Bc = cur.Bc;
            // 빨간 구슬 이동
            while(true){
                if(board[next_Rr][next_Rc] != '#' && board[next_Rr][next_Rc] != 'O'){
                    next_Rr += dr[i];
                    next_Rc += dc[i];
                } else{
                    if(board[next_Rr][next_Rc] == '#'){
                        next_Rr -= dr[i];
                        next_Rc -= dc[i];
                    }
                    break;
                }
            }
            // 파란 구슬 이동
            while(true){
                if(board[next_Br][next_Bc] != '#' && board[next_Br][next_Bc] != 'O'){
                    next_Br += dr[i];
                    next_Bc += dc[i];
                } else{
                    if(board[next_Br][next_Bc] == '#'){
                        next_Br -= dr[i];
                        next_Bc -= dc[i];
                    }
                    break;
                }
            }

            // 빨간 구슬과 파란 구실의 위치가 겹친 경우
            if(next_Rr == next_Br && next_Rc == next_Bc){
                if(board[next_Rr][next_Rc] != 'O'){
                    int red_dist = abs(next_Rr - cur.Rr) + abs(next_Rc - cur.Rc);
				    int blue_dist = abs(next_Br - cur.Br) + abs(next_Bc - cur.Bc);
                    if (blue_dist > red_dist) {
						next_Br -= dr[i];
                        next_Bc -= dc[i];
					} else{
						next_Rr -= dr[i];
						next_Rc -= dc[i];
					}
                }
            }

            // 다음 방문 위치가 첫 방문인 경우
            if(!visited[next_Rr][next_Rc][next_Br][next_Bc]){
                INFO next;
                next.Rr = next_Rr; next.Rc = next_Rc;
                next.Br = next_Br; next.Bc = next_Bc;
                next.round = cur.round + 1;
                q.push(next);
            }
        }
    }

    return -1;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<string> board(N, "");
    for(int i = 0; i < N; ++i){
        cin >> board[i];
        for(int j = 0; j < M; ++j){
            if(board[i][j] == 'R'){
                start.Rr = i;
                start.Rc = j;
            }
            else if(board[i][j] == 'B'){
                start.Br = i;
                start.Bc = j;
            }
        }
    }
    start.round = 0;

    cout << solve(board) << "\n";

    return 0;
}
