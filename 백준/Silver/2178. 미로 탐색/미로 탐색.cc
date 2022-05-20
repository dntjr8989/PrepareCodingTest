#include <stdio.h>
#include <queue>

using namespace std;

int N, M;
char map[100][102];

struct Position{
    int y; int x; int move;
    Position(int yy, int xx, int m) : y(yy), x(xx), move(m){};
};

int BFS(){
    int dy[4] = {0, 0, 1, -1};
    int dx[4] = {1, -1, 0, 0};
    
    queue<Position> q;
    q.push(Position(0, 0, 1));
    
    bool check[100][102] = {false,};
    check[0][0] = true;
    
    int min = 15000;
    while(!q.empty()){
        Position t = q.front();
        q.pop();
        if(t.y == N-1 && t.x == M-1){
            if(min > t.move) min = t.move;
        }
        for(int i=0; i<4; i++){
            int ty = t.y+dy[i]; int tx = t.x+dx[i];

            if(ty >= 0 && ty < N && tx >= 0 && tx < M){
                
                if(map[ty][tx] == '1' && check[ty][tx] == false){
                    q.push(Position(ty,tx,t.move+1));
                    check[ty][tx] = true;
                }
            }
        }
    }
    return min;
};

int main()
{
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        scanf("%s", map[i]);
    }
    printf("%d\n", BFS());
}