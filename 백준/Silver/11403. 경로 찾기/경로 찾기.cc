#include <stdio.h>
#define INF 10000

int main()
{
    int N;
    int dp[100][100];

    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            dp[i][j] = INF;
        }
    }
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int t;
            scanf("%d", &t);
            if(t == 1) dp[i][j] = 1;
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<N; k++){
                dp[j][k] = (dp[j][k] < (dp[j][i] + dp[i][k])) ? dp[j][k] : (dp[j][i] + dp[i][k]);
            }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(dp[i][j] >= INF) printf("0 ");
            else printf("1 ");
        }
        printf("\n");
    }
}