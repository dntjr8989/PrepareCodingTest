#include <stdio.h>
#include <queue>

using namespace std;

int K;
int W, H;
int map[200][200];
int answer = 40000;

void input()
{
    scanf("%d", &K);
    scanf("%d %d", &W, &H);
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            scanf("%d", &map[i][j]);
        }
    }
};

struct Position
{
    int y; int x; int k; int move;
    Position(int Y, int X, int K, int Move) : y(Y), x(X), k(K), move(Move) {}
};

void BFS()
{
    queue<Position> q;
    int check[200][200][31];
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            for(int k=0; k<=K; k++){
                check[i][j][k] = 40000;
            }
        }
    }
    q.push(Position(0, 0, K, 0));
    check[0][0][K] = 0;

    while(!q.empty())
    {
        int ty = q.front().y; int tx = q.front().x; int tk = q.front().k; int tm = q.front().move;
        q.pop();
        
        if(ty == H-1 && tx == W-1)
        {
            if(answer > tm) answer = tm;
        }
        if(tm+1 >= answer) continue; 

        int dy[12] = {1, -1 , 0, 0, -1, 1, -1, 1, 2, 2, -2, -2};
        int dx[12] = {0, 0, 1, -1, -2, -2, 2, 2, 1, -1, 1, -1};
        
        for(int i=0; i<4; i++){
            int yy = ty+dy[i]; int xx = tx+dx[i];
            if(yy < 0 || yy >= H || xx < 0 || xx >= W) continue;
            if(map[yy][xx] == 1) continue;
            if(check[yy][xx][tk] <= tm+1) continue;
            q.push(Position(yy, xx, tk, tm+1));
            check[yy][xx][tk] = tm+1;
        }

        if(tk >= 1)
        {
            for(int i=4; i<12; i++)
            {
                int yy = ty+dy[i]; int xx = tx+dx[i];
                if(yy < 0 || yy >= H || xx < 0 || xx >= W) continue;
                if(map[yy][xx] == 1) continue;
                if(check[yy][xx][tk-1] <= tm+1) continue;
                q.push(Position(yy, xx, tk-1, tm+1));
                check[yy][xx][tk-1] = tm+1;
            }
        }
    }

    if(answer >= 40000) printf("-1\n");
    else printf("%d\n", answer);
}

int main()
{
    input();
    BFS();
}