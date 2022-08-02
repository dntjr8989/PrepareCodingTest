#include <stdio.h>
#include <queue>

using namespace std;

int N, M;
int map[50][50];
bool check1[50][50] = {false, };

int BFS(int y, int x)
{

    bool check[50][50] = {false,};
    queue< pair<int, int> > q;
    int cnt = 0;

    q.push(make_pair(y, x));
    check[y][x] = true;
    check1[y][x] = true;

    int dy[4] = {0, -1, 0, 1};
    int dx[4] = {-1, 0, 1, 0};

    while(!q.empty())
    {
        int ty = q.front().first; int tx = q.front().second;
        q.pop();
        cnt++;
        int t = map[ty][tx];
        for(int i=0; i<4; i++){
            int yy = ty+dy[i]; int xx = tx+dx[i];
            if((t & 1) != 1 && yy >= 0 && yy < M && xx >= 0 && xx < N)
            {
                if(check[yy][xx] == false)
                {
                    q.push(make_pair(yy, xx));
                    check[yy][xx] = true;
                    check1[yy][xx] = true;
                }
            } 
            t = t >> 1;
        }
    }
    return cnt;
}

int main()
{
    scanf("%d %d", &N, &M);

    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &map[i][j]);
        }
    }

    int max = -1; int cnt = 0;
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if(check1[i][j] == true ) continue;

            int t = BFS(i, j);
            if(t > max) max = t;
            cnt++;
        }
    }

    int max1 = -1;
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            for(int k=1; k<=8; k=k*2)
            {
                if(k > map[i][j]) break;
                map[i][j] = map[i][j] - k;
                int t = BFS(i, j);
                if(max1 < t) max1 = t;
                
                map[i][j] = map[i][j] + k;
            }
        }
    }

    printf("%d\n%d\n%d\n", cnt, max, max1);
}