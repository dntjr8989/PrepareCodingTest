#include <stdio.h>
#include <queue>

using namespace std;

int H, W;
char map[50][51];

struct Pos{
    int y, x, time;
};

int BFS(int y, int x)
{
    queue<Pos> q;
    Pos t; t.y = y; t.x = x; t.time = 0;
    q.push(t);
    
    bool check[50][50] = {false,};
    check[y][x] = true;

    int dy[4] = {1, -1, 0, 0};
    int dx[4] = {0, 0, 1, -1};

    int max = -1;
    while(!q.empty())
    {
        Pos temp = q.front();
        q.pop();
        if(max < temp.time) max = temp.time;
        for(int i=0; i<4; i++){
            int ty = temp.y+dy[i]; int tx = temp.x+dx[i]; int time = temp.time+1;
            if(ty < 0 || ty >= H || tx < 0 || tx >= W) continue;
            if(check[ty][tx] == true) continue;
            if(map[ty][tx] == 'W') continue;
            check[ty][tx] = true;
            
            Pos t; t.y = ty; t.x = tx; t.time = time;
            q.push(t);
        }
    }

    return max;
}

int main()
{
    scanf("%d %d", &H, &W);
    for(int i=0; i<H; i++){
        scanf("%s", map[i]);
    }

    int max = -1;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(map[i][j] == 'L')
            {
                int t = BFS(i, j);
                max = (max > t) ? max : t;
            }
        }
    }
    
    printf("%d\n", max);

    return 0;
}