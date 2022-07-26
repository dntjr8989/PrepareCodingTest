#include <stdio.h>
#include <queue>
#define INF 2500
using namespace std;

bool map[50][50];
int N, M;

struct Position{
    short y, x, d;
    Position(short Y, short X, short D) : y(Y), x(X), d(D) {}
};

short BFS(int y, int x)
{
    queue<Position> q;
    bool check[50][50] = {false,};
    short dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};
    short dx[8] = {1, -1, 0, 0, 1, -1, -1, 1};

    q.push(Position(y,x,0));
    check[y][x] = true;

    while(!q.empty())
    {
        Position t = q.front();
        q.pop();

        if(map[t.y][t.x] == true)
        {
            return t.d;
        }

        for(int i=0; i<8; i++){
            short ty = t.y + dy[i]; short tx = t.x + dx[i];

            if(ty < 0 || ty >= N || tx < 0 || tx >= M) continue;
            if(check[ty][tx] == true) continue;
            q.push(Position(ty,tx,t.d+1));
            check[ty][tx] = true;
        }
    }
    return INF;
}

int main()
{

    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%d", &map[i][j]);
        }
    }
    short max = -1;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j] == true) continue;
            short t = BFS(i, j);
            if( max < t) max = t;
        }
    }
    printf("%hd\n", max);
}