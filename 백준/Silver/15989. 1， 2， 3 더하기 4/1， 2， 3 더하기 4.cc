#include <stdio.h>

int dp[10001][4];

int DP(int n, int num)
{
    if(num == 0)
    {
        if(n == 0) return 1;
        else return 0;
    }

    if(dp[n][num] != -1) return dp[n][num];

    int sum = 0;
    for(int i=0; ; i++){
        if(n - num*i >= 0)
        {
            sum = sum + DP(n - num * i, num-1);
        }
        else
        {
            break;
        }
    }
    dp[n][num] = sum;

    return dp[n][num];
}

int main()
{
    //dp 초기화
    for(int i=0; i<=10000; i++){
        for(int j=0; j<4; j++) dp[i][j] = -1;
    }
    //입력
    int T;
    scanf("%d", &T);

    for(int tc=0; tc<T; tc++){
        int n;
        scanf("%d", &n);

        printf("%d\n", DP(n, 3));
    }
}