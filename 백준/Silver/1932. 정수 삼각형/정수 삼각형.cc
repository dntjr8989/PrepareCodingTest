#include <stdio.h>

int Max(int a, int b){
    if( a > b) return a;
    return b;
}

int main()
{
    int n;
    int dp[500][500] = {0,};
    int triagle[500][500];

    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            scanf("%d", &triagle[i][j]);
        }
    }

    dp[0][0] = triagle[0][0];
    for(int i=1; i<n; i++){
        for(int j=0; j<=i; j++){
            if(j != i) dp[i][j] = Max(dp[i][j], dp[i-1][j]+triagle[i][j]);
            if(j != 0) dp[i][j] = Max(dp[i][j], dp[i-1][j-1]+triagle[i][j]);
        }
    }
    int answer = -1;
    for(int j=0; j<n; j++){
        if(answer < dp[n-1][j]) answer = dp[n-1][j];
    }
    printf("%d\n", answer);
}