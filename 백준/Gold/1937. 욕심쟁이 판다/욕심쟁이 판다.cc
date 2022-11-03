#include <stdio.h>

int n;
int map[500][500];
int dp[500][500];
bool check[500][500] = {false,};

void input()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &map[i][j]);
            dp[i][j] = -1;
        }
    }
}

int func(int y, int x, int num)
{
    if(map[y][x] <= num)
    {
        return 0;
    }
    if(dp[y][x] != -1) return dp[y][x];

    int dy[4] = {1, -1, 0, 0};
    int dx[4] = {0, 0, 1, -1};

    int max = -1;
    for(int i=0; i<4; i++){
        if(y+dy[i] >= n || y+dy[i] < 0 || x+dx[i] >= n || x+dx[i] < 0) continue;
        if(check[y+dy[i]][x+dx[i]] == true) continue;
        check[y+dy[i]][x+dx[i]] = true;
        int t = func(y+dy[i], x+dx[i], map[y][x]) + 1;
        check[y+dy[i]][x+dx[i]] = false;

        if(max < t)
        {
            max = t;
        }
    }
    dp[y][x] = max;
    return dp[y][x];
}

int main()
{
    input();
    int max = -1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(dp[i][j] == -1)
            {
                check[i][j] = true;
                func(i, j, -1);
                check[i][j] = false;
            }

            if(dp[i][j] > max) max = dp[i][j];
        }
    }
    printf("%d\n", max);
}