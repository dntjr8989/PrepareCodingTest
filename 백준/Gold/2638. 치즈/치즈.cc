#include <stdio.h>
#include <queue>

using namespace std;

bool checkMap[100][100];        
int N, M;
int map[100][100];

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

void BFS(int y, int x)
{
    queue< pair<int ,int > > q;
    q.push(make_pair(y, x));
    checkMap[y][x] = true;

    while(!q.empty())
    {
        int y = q.front().first; int x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int ty = y+dy[i]; int tx = x+dx[i];
            if(ty < 0 || ty >= N || tx < 0 || tx >= M) continue;
            if(checkMap[ty][tx] == true) continue;
            if(map[ty][tx] == 1) continue;

            q.push(make_pair(ty, tx));
            checkMap[ty][tx] = true;
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%d", &map[i][j]);
        }
    }

    int time;
    for(time=1; ; time++)
    {
        //checkMap 초기화
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                checkMap[i][j] = false;
            }
        }
        //외부 공간 확인
        for(int i=0; i<N; i++){
            if(checkMap[i][0] == false) BFS(i, 0);
            if(checkMap[i][M-1] == false) BFS(i, M-1);
        }
        for(int i=0; i<M; i++){
            if(checkMap[0][i] == false) BFS(0, i);
            if(checkMap[N-1][i] == false) BFS(N-1, i);
        }

        //녹을 치즈 지우기
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(map[i][j] == 1)
                {
                    int cnt = 0;
                    for(int k=0; k<4; k++){
                        if(checkMap[i+dy[k]][j+dx[k]] == true) cnt++;
                    }
                    if(cnt >= 2)
                    {
                        map[i][j] = 0;
                    }
                }
            }
        }

        //남은 치즈 있는 지 확인
        bool flag = false;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(map[i][j] == 1){
                    flag = true; break;
                }
            }
            if(flag == true) break;
        }

        if(flag == false)
        {
            printf("%d\n", time);
            return 0;
        }
    }

    return 0;
}