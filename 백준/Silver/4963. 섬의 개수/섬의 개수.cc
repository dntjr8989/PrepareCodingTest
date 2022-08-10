#include <stdio.h>
#include <queue>

using namespace std;

int BFS(int w, int h, int map[50][50])
{
    bool check[50][50] = {false,};
    int cnt = 0;

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(map[i][j] == 1 && check[i][j] == false)
            {
                cnt++;

                queue< pair<int, int> > q;
                q.push(make_pair(i, j));
                check[i][j] = true;

                int dy[8] = {1, 0, -1, 0, 1, 1, -1, -1};
                int dx[8] = {0, 1, 0, -1, 1, -1, 1, -1};
                while(!q.empty())
                {
                    int y = q.front().first; int x = q.front().second;
                    q.pop();
                    for(int k=0; k<8; k++){
                        int ty = y + dy[k]; int tx = x + dx[k];
                        if(ty < 0 || ty >= h || tx < 0 || tx >= w) continue;
                        if(map[ty][tx] == 0) continue;
                        if(check[ty][tx] == true) continue;
                        q.push(make_pair(ty, tx));
                        check[ty][tx] = true;
                    }
                }
            }
        }
    }

    return cnt;
}

int main()
{
    while(1)
    {
        int w, h;
        scanf("%d %d", &w, &h);
        
        if(w == 0 && h == 0) break;

        int map[50][50];

        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                scanf("%d", &map[i][j]);
            }
        }

        printf("%d\n", BFS(w, h, map));
    }
}