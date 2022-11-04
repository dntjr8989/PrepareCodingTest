#include <stdio.h>
#include <queue>

using namespace std;

int N;
int map[100][100];
bool checkMap[100][100] = {false,};
int islandCnt = 1;

int Min = 100000;

void input()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &map[i][j]);
        }
    }
};

void BFS(int y, int x)
{
    queue< pair<int, int> > q;
    q.push(make_pair(y, x));
    checkMap[y][x] = true;
    map[y][x] = islandCnt;

    while(!q.empty())
    {
        int ty = q.front().first; int tx = q.front().second;
        q.pop();

        int dy[4] = {1, -1 ,0 ,0};
        int dx[4] = {0, 0, 1, -1};

        for(int i=0; i<4; i++){
            if(ty+dy[i] < 0 || ty+dy[i] >= N || tx+dx[i] < 0 || tx+dx[i] >= N ) continue;
            if(checkMap[ty+dy[i]][tx+dx[i]] == true) continue;
            if(map[ty+dy[i]][tx+dx[i]] == 0) continue;

            q.push(make_pair(ty+dy[i], tx+dx[i]));
            checkMap[ty+dy[i]][tx+dx[i]] = true;
            map[ty+dy[i]][tx+dx[i]] = islandCnt;
        }
    }
};

void findIsland()
{
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
        {
            if(checkMap[i][j] == false && map[i][j] != 0)
            {
                BFS(i, j);
                islandCnt++;
            }
        }
    }
};

struct Position{
    int y, x, d;
    Position(int Y, int X, int D) : y(Y), x(X), d(D){}
};

void findMinBFS(int y, int x, int islandNum)
{
    queue<Position> q;
    q.push(Position(y, x, 0));
    checkMap[y][x] = true;
    bool check[100][100] = {false, };

    while(!q.empty())
    {
        int ty = q.front().y; int tx = q.front().x; int td = q.front().d;
        q.pop();

        int dy[4] = {1, -1 ,0 ,0};
        int dx[4] = {0, 0, 1, -1};

        for(int i=0; i<4; i++)
        {
            int yy = ty+dy[i]; int xx = tx+dx[i];
            if(yy < 0 || yy >= N || xx < 0 || xx >= N) continue;
            
            if(map[yy][xx] == 0 && check[yy][xx] == false)
            {
                if(Min > td+1)
                {
                    q.push(Position(yy, xx, td+1));
                    check[yy][xx] = true;
                }
            }
            else if(map[ty][tx] != 0 && map[yy][xx] == islandNum && checkMap[yy][xx] == false)
            {
                q.push(Position(yy, xx, td));
                checkMap[yy][xx] = true;
            }
            else if(map[yy][xx] > islandNum)
            {
                if(Min > td+1){
                    Min = td+1;
                }
            }
        }
    }
}

void findMinDistance()
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++) checkMap[i][j] = false;
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(checkMap[i][j] == false && map[i][j] != 0)
            {
                findMinBFS(i, j, map[i][j]);
            }
        }
    }

    printf("%d\n", Min-1);
}

int main()
{
    input();
    findIsland();
    findMinDistance();
}