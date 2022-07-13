#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;


int M, N, K;
bool map[100][100] = {false,};
bool check[100][100] = {false,};
vector<int> answer;

void BFS(int y, int x){
    int cnt = 0;
    int dy[4] = {1, -1, 0, 0};
    int dx[4] = {0, 0, 1, -1};
    
    queue< pair<int, int > > q;
    q.push(make_pair(y, x));
    check[y][x] = true;
    cnt++;
    while(!q.empty())
    {
        int ty = q.front().first; int tx = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int yy = ty+dy[i]; int xx = tx+dx[i];
            if(yy < 0 || yy >= M || xx < 0 || xx >= N) continue;
            if(check[yy][xx] == true )continue;
            if(map[yy][xx] == true) continue;

            q.push(make_pair(yy, xx));
            check[yy][xx] = true;
            cnt++;
        }
    }
    answer.push_back(cnt);
}

void solve()
{
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if(check[i][j] == false && map[i][j] == false)
            {
                BFS(i, j);
            }
        }
    }
}

int main()
{
    scanf("%d %d %d", &M, &N, &K);
    for(int i=0; i<K; i++){
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        for(int j=x1; j<x2; j++){
            for(int k=y1; k<y2; k++){
                map[k][j] = true;
            }
        }
    }

   
    solve();
    sort(answer.begin(), answer.end());

    printf("%d\n", answer.size());
    for(int i=0; i<answer.size(); i++){
        printf("%d ", answer[i]);
    }
    printf("\n");
}