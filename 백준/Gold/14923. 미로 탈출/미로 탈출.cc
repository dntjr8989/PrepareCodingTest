#include <stdio.h>
#include <queue>

using namespace std;

struct Pos{
    int x, y, t;
    bool flag;
    Pos(int X, int Y, int T, bool Flag) : x(X), y(Y), t(T), flag(Flag){}
};

int N, M;
int Hx, Hy;
int Ex, Ey;
int map[1001][1001];

int BFS()
{
    queue<Pos> q;
    bool check[1001][1001][2] = {false, };
    int dy[4] = {0, 0, 1, -1};
    int dx[4] = {1, -1, 0, 0};

    q.push(Pos(Hx, Hy, 0, false));
    check[Hx][Hy][0] = false;

    while(!q.empty())
    {
        Pos temp = q.front();
        q.pop();
        if(temp.x == Ex && temp.y == Ey) return temp.t;

        for(int i=0; i<4; i++){
            int tx = temp.x+dx[i]; int ty = temp.y+dy[i];
            if(tx < 1 || tx > N || ty < 1 || ty > M) continue;
            if(check[tx][ty][temp.flag] == true) continue;

            if(map[tx][ty] == 1 && temp.flag == true) continue;

            if(map[tx][ty] == 1 && temp.flag == false) { q.push(Pos(tx,ty,temp.t+1, true));  check[tx][ty][true] = true;}

            if(map[tx][ty] == 0) { q.push(Pos(tx,ty,temp.t+1, temp.flag)); check[tx][ty][temp.flag] = true;}
        }
    }

    return -1;
};

int main()
{
    //입력
    scanf("%d %d", &N, &M);
    scanf("%d %d", &Hx, &Hy);
    scanf("%d %d", &Ex, &Ey);

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            scanf("%d", &map[i][j]);
        }
    }
    //출력
    printf("%d\n", BFS());

    return 0;
}