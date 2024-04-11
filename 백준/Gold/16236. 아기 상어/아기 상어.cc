#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX_FIELD 20

int N;
int field[MAX_FIELD][MAX_FIELD];
int const dr[] = {-1, 0, 0, 1};
int const dc[] = {0, -1, 1, 0};

struct Shark
{
    int row, col;
    int size = 2;
    int eat = 0;
    int distance = 0;
};

bool eatFish(Shark &shark)
{
    bool visited[MAX_FIELD][MAX_FIELD] = {false};
    bool ate = false;
    queue<Shark> q;
    q.push(shark);
    visited[shark.row][shark.col] = true;
    
    while(!q.empty()){
        Shark cur = q.front(); q.pop();
        if(field[cur.row][cur.col] && field[cur.row][cur.col] < cur.size){
            ++cur.eat;
            if(cur.size == cur.eat){
                ++cur.size;
                cur.eat = 0;
            }
            shark = cur;
            ate = true;
            break;
        }
        for(int i = 0; i < 4; ++i){
            Shark next = cur;
            next.row += dr[i];
            next.col += dc[i];
            next.distance += 1;
            if(next.row < N && next.row >= 0 && next.col < N && next.col >= 0){
                if(!visited[next.row][next.col] && field[next.row][next.col] <= next.size){
                    visited[next.row][next.col] = true;                    
                    q.push(next);
                }
            }
        }
    }
    while(!q.empty()){
        Shark cur = q.front(); q.pop();
        if(shark.distance != cur.distance)
            break;
        if(field[cur.row][cur.col] && field[cur.row][cur.col] < cur.size){
            if(cur.row < shark.row){
                shark.row = cur.row;
                shark.col = cur.col;
            }
            else if(cur.row == shark.row && cur.col < shark.col){
                shark.row = cur.row;
                shark.col = cur.col;
            }
        }
    }
    if(ate){
        field[shark.row][shark.col] = 0;
        return true;
    }
    
    return false;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Shark shark;
    cin >> N;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            cin >> field[i][j];
            if(field[i][j] == 9){
                shark.row = i;
                shark.col = j;
                field[i][j] = 0;
            }
        }
    }

    while(eatFish(shark));

    cout << shark.distance << "\n";

    return 0;
}