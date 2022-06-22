#include <stdio.h>
#include <string.h>

int main()
{
    char A[1001];
    char B[1001];
    int dp[1001][1001];

    scanf("%s", A);
    scanf("%s", B);

    for(int i=0; i<=strlen(B); i++)
    {
        dp[0][i] = 0;
    }
    for(int i=1; i<=strlen(A); i++){
        dp[i][0] = 0;
        for(int j=1; j<=strlen(B); j++){
            if(A[i-1] == B[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else{
                dp[i][j] = (dp[i-1][j] > dp[i][j-1]) ? dp[i-1][j] : dp[i][j-1];
            }
        }
    }

    printf("%d\n", dp[strlen(A)][strlen(B)]);
}