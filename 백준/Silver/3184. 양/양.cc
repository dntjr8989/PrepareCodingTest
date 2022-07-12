#include <stdio.h>
#include <queue>

using namespace std;

char map[250][251];
int R, C;
bool check[250][250] = {false,};
int sheep = 0; int wolf = 0;

void input()
{
    scanf("%d %d", &R, &C);
    for(int i=0; i<R; i++){
        scanf("%s", map[i]);
    }
};

void BFS(int y, int x){

    int dy[4] = {1, -1, 0, 0};
    int dx[4] = {0, 0, 1, -1};

    queue< pair<int, int > > q;
    check[y][x] = true;
    q.push(make_pair(y, x));

    int s = 0; int w = 0;
    while(!q.empty()){
        int ty = q.front().first; int tx = q.front().second;
        q.pop();
        
        if(map[ty][tx] == 'v') w++;
        else if(map[ty][tx] == 'o') s++;

        for(int i=0; i<4; i++){
            int yy = ty+dy[i]; int xx = tx+dx[i];
            if(yy < 0 || yy >= R || xx < 0 || xx >= C) continue;
            if(map[yy][xx] == '#') continue;
            if(check[yy][xx] == true) continue;

            q.push(make_pair(yy, xx));
            check[yy][xx] = true;
        }
    }

    if(s > w){
        sheep = sheep + s;
    }
    else{
        wolf = wolf + w;
    }
}

void solve()
{
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(map[i][j] != '#' && check[i][j] == false){
                BFS(i, j);
            }
        }
    }
};

int main()
{
    input();
    solve();
    printf("%d %d\n", sheep, wolf);
}