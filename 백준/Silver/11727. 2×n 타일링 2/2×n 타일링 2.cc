#include <stdio.h>
#define MOD 10007

int main()
{
    int n;
    int dp[1001];

    dp[1] = 1;
    dp[2] = 3;

    scanf("%d", &n);
    for(int i=3; i<=n; i++){
        dp[i] = ( (dp[i-2]*2)%MOD + dp[i-1])%MOD;
    }

    printf("%d\n", dp[n]);
}