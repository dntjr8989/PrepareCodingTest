#include <stdio.h>
#define INF 1001

using namespace std;

int N, A[1000];
int dp[1000];

int func(int index)
{
    if(index >= N) return INF;

    if(index == N-1) return 0;

    if(dp[index] != -1) return dp[index];

    int min = INF;
    for(int i=1; i<=A[index]; i++){
        int t = func(index+i)+1;
        if(min > t) min = t;
    }
    dp[index] = min;

    return min;
}

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &A[i]);
        dp[i] = -1;
    }

    int answer = func(0);
    if(answer == INF) answer = -1;

    printf("%d\n", answer);
}