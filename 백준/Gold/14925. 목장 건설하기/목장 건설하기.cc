#include <stdio.h>

int findMin(int a, int b, int c)
{
    int min = a;

    if(min > b) min = b;
    if(min > c) min = c;

    return min;
}

int main()
{
    int M, N;
    int ground[1001][1001];
    int dp[1001][1001];

    //입력
    scanf("%d %d", &M, &N);
    for(int i=1; i<=M; i++){
        for(int j=1; j<=N; j++){
            scanf("%d", &ground[i][j]);
        }
    }
    //dp 배열 초기화
    for(int i=0; i<=M; i++){
        for(int j=0; j<=N; j++){
            dp[i][j] = 0;
        }
    }
    //
    for(int y=1; y<=M; y++){
        for(int x=1; x<=N; x++){
            if(ground[y][x] != 0) {dp[y][x] = 0; continue;}

            dp[y][x] = findMin(dp[y-1][x], dp[y-1][x-1], dp[y][x-1]) + 1;
        }
    }

    int max = -1;
    for(int y=0; y<=M; y++){
        for(int x=0; x<=N; x++){
            if(max < dp[y][x]){max = dp[y][x];}
        }
    }

    //출력
    printf("%d\n", max);
}