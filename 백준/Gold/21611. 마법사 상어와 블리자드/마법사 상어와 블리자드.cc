#include <stdio.h>

int N, M;
int map[50][50];
int magic[100][2]; //d s
int a[2501];
int sum = 0;

void destroy(int index)
{
    int dy[5] = {0, -1, 1, 0 ,0};
    int dx[5] = {0, 0, 0, -1, 1};

    int y = (N+1)/2; int x = (N+1)/2;
    for(int i=1; i<=magic[index][1]; i++){
        y = y + dy[magic[index][0]]; x = x + dx[magic[index][0]];
        if(y <= 0 || y > N || x <= 0 || x > N) continue;
        map[y][x] = 0;
    }
}

void twoToOneArray()
{
    int index = N*N;
    int t = 1;
    for(int i=N-1; i>=2; i=i-2)
    {
        for(int j=t; j<t+i; j++){
            a[index] = map[t][j]; index--;
        }
        for(int j=t; j<t+i; j++){
            a[index] = map[j][N-t+1]; index--;
        }
        for(int j=N-t+1; j>N-t+1-i; j--)
        {
            a[index] = map[N-t+1][j]; index--;
        }
        for(int j=N-t+1; j>N-t+1-i; j--){
            a[index] = map[j][t]; index--;
        }
        t++;
    }
}

void oneToTwoArray()
{
    int index = N*N;
    int t = 1;
    for(int i=N-1; i>=2; i=i-2)
    {
        for(int j=t; j<t+i; j++){
            map[t][j] = a[index]; index--;
        }
        for(int j=t; j<t+i; j++){
            map[j][N-t+1]=a[index]; index--;
        }
        for(int j=N-t+1; j>N-t+1-i; j--)
        {
            map[N-t+1][j]=a[index]; index--;
        }
        for(int j=N-t+1; j>N-t+1-i; j--){
            map[j][t] = a[index]; index--;
        }
        t++;
    }
}

void moveMarvel()
{
    int blank = 0;
    for(int i=2; i<=N*N; i++){
        if(a[i] == 0) {blank++; continue;}
        a[i-blank] = a[i];
    }
    for(int i=N*N; i>N*N-blank; i--){
        a[i] = 0;
    }
}

bool bomb()
{
    int cnt = 0;
    int t=-1;
    bool flag = false;
    for(int i=2; i<=N*N; i++){
        if(a[i] != t) {
            if(cnt >= 4){
                for(int j=i-1; j>i-1-cnt; j--){
                    sum = sum + a[j];
                    a[j] = 0;
                }
                flag = true;
            }
            t=a[i]; cnt = 1; continue;
        }
        if(a[i] == t) {cnt++;}
    }
    return flag;
}

void changeMarvel()
{
    int temp[2501] = {0,};
    int tempIndex = 2;
    int cnt = 1;
    int t = a[2];
    for(int i=3; i<=N*N; i++){
         if(t == 0 )break;
         if(a[i] == 0) break;
         if(a[i] != t) {
            temp[tempIndex] = cnt; tempIndex++;
            if(tempIndex > N*N) break;
            temp[tempIndex] = t; tempIndex++;
            if(tempIndex > N*N) break;
            t=a[i]; cnt = 1; continue;
        }
        if(a[i] == t) {cnt++;}
    }
    if(tempIndex <= N*N && t != 0){
        temp[tempIndex] = cnt; tempIndex++;
        if(tempIndex <= N*N)
        {
            temp[tempIndex] = t; tempIndex++;
        }
    }

    for(int i=1; i<=N*N; i++){
        a[i] = temp[i];
    }
}

void solve()
{   
    for(int i=0; i<M; i++)
    {
        destroy(i);

        twoToOneArray();

        moveMarvel();
        while(bomb()){
            moveMarvel();
        }

        changeMarvel();

        oneToTwoArray();
    }
    
    return;
}

int main()
{
    scanf("%d %d", &N, &M);
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            scanf("%d", &map[i][j]);
        }
    }
    for(int i=0; i<M; i++){
        scanf("%d %d", &magic[i][0], &magic[i][1]);
    }
    solve();
    
    printf("%d\n", sum);
}