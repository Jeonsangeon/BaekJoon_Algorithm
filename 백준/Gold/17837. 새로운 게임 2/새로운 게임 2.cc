#include <iostream>
#include <deque>

#define MAX_N 13
#define MAX_K 10

using namespace std;

struct Piece {
    int row;
    int col;
    int dir;
};

int N, K, ret;
int color[MAX_N][MAX_N];
deque<int> board[MAX_N][MAX_N];
Piece pieces[MAX_K];

int dr[5] = {0, 0, 0, -1, 1};
int dc[5] = {0, 1, -1, 0, 0};

void printDebugging() {
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            cout << board[i][j].size() << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void turn_over(int idx) {
    if(pieces[idx].dir == 1) pieces[idx].dir = 2;
    else if(pieces[idx].dir == 2) pieces[idx].dir = 1;
    else if(pieces[idx].dir == 3) pieces[idx].dir = 4;
    else if(pieces[idx].dir == 4) pieces[idx].dir = 3;
}

bool validate(int r, int c) {
    return r > 0 && r <= N && c > 0 && c <= N;
}

bool move(int idx) {
    Piece &piece = pieces[idx];
    deque<int> dq;
    while(!board[piece.row][piece.col].empty()) {
        int cur = board[piece.row][piece.col].back(); 
        board[piece.row][piece.col].pop_back();
        dq.push_front(cur);
        if(cur == idx) break;
    }

    int nr = piece.row + dr[piece.dir];
    int nc = piece.col + dc[piece.dir];
    if(!validate(nr, nc) || color[nr][nc] == 2) {
        turn_over(idx);
        nr = piece.row + dr[piece.dir];
        nc = piece.col + dc[piece.dir];
        if(!validate(nr, nc) || color[nr][nc] == 2) {
            while(!dq.empty()) {
                int cur = dq.front(); dq.pop_front();
                board[piece.row][piece.col].push_back(cur);
            }
            return false;
        }
    }
        
    if(color[nr][nc] == 0) {
        while(!dq.empty()) {
            int cur = dq.front(); dq.pop_front();
            board[nr][nc].push_back(cur);
            pieces[cur].row = nr; pieces[cur].col = nc;
        }
    } else {
        while(!dq.empty()) {
            int cur = dq.back(); dq.pop_back();
            board[nr][nc].push_back(cur);
            pieces[cur].row = nr; pieces[cur].col = nc;
        }
    }

    if(board[nr][nc].size() >= 4)
        return true;
    return false;
}

bool turn() {
    ++ret;
    for(int i = 0; i < K; ++i)
        if(move(i))
            return true;
    return false;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= N; ++j)
            cin >> color[i][j];

    for(int i = 0; i < K; ++i) {
        cin >> pieces[i].row >> pieces[i].col >> pieces[i].dir;
        board[pieces[i].row][pieces[i].col].push_back(i);
    }

    while(ret <= 1000) {
        if(turn()) {
            cout << ret << "\n";
            return 0;
        }
    }

    cout << -1 << "\n";
    return 0;
}