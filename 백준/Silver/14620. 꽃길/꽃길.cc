#include <stdio.h>
#define INF 200000

int N;
int G[10][10];
int min = INF;
void input()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &G[i][j]);
        }
    }
};

bool canSeed(int i, int j, bool map[10][10]){
    if(i-1 < 0 || i+1 >= N || j-1 < 0 || j+1 >= N) return false;
    if(map[i][j] == true || map[i-1][j] == true || map[i+1][j] == true || map[i][j+1] == true || map[i][j-1] == true) return false;

    return true;
};

void solve(bool map[10][10], int cnt, int sum)
{   
    if(cnt == 3){
        if(min > sum){
            min = sum;
        }
        return;
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            
            if(canSeed(i, j, map))
            {
                map[i][j] = map[i-1][j] = map[i+1][j] = map[i][j-1] = map[i][j+1] = true;
                solve(map, cnt+1, sum + G[i][j] + G[i-1][j] + G[i+1][j] + G[i][j-1] + G[i][j+1]);
                map[i][j] = map[i-1][j] = map[i+1][j] = map[i][j-1] = map[i][j+1] = false;
            }
        }
    }
};

int main()
{
    input();
    bool map[10][10] = {false,};
    solve(map, 0, 0);
    printf("%d", min);
}