#include <stdio.h>
#include <string.h>

int main()
{
    char A[1001];
    char B[1001];
    int dp[1001][1001];
    char answer[1001];

    scanf("%s", A);
    scanf("%s", B);

    for(int i=0; i<=strlen(B); i++){

        for(int j=0; j<=strlen(A); j++){
            dp[i][j] = 0;
        }
    }

    for(int i=1; i<=strlen(B); i++){
        for(int j=1; j<=strlen(A); j++){
            if(B[i-1] == A[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = (dp[i-1][j] > dp[i][j-1]) ? dp[i-1][j] : dp[i][j-1];
            }
        }
    }
    printf("%d\n", dp[strlen(B)][strlen(A)]);
    int len = dp[strlen(B)][strlen(A)];
    if(len > 0){
        for(int j=strlen(B); j>=0; j--)
        {
            for(int i=strlen(A); i>=0; i--){
                if(len > dp[j][i] && dp[j][i+1] == len){
                    answer[len] = A[i];
                    int t = j-1;
                    while(dp[t][i+1] == len){
                        t--;
                    }
                    j = t+1;
                    len--;
                    break;
                }
            }
            if(len <= 0){
                break;
            }
        }
        for(int i=1; i<=dp[strlen(B)][strlen(A)]; i++){
             printf("%c", answer[i]);
        }
        printf("\n");
    }
}