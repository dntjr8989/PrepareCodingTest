#include <stdio.h>
#define INF 1000000

int Max(int a, int b){
    if(a > b) return a;
    return b;
}
int Max(int a, int b, int c){
    if(a >= b && a >= c) return a;
    if(b >= a && b >= c) return b;
    if(c >= a && c >= b) return c;
}
int Min(int a, int b){
    if(a < b) return a;
    return b;
}
int Min(int a, int b, int c){
    if(a <= b && a <= c) return a;
    if(b <= a && b <= c) return b;
    if(c <= a && c <= b) return c;
}

int main()
{
    int dpMin[3];
    int dpMax[3];

    int N;
    int map[100001][3];
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d %d %d", &map[i][0], &map[i][1], &map[i][2]);
    }
    map[N][0] = map[N][1] = map[N][2] = 0;

    for(int i=0; i<3; i++){
        dpMax[i] = dpMin[i] = map[0][i];
    }
    for(int i=1; i<=N; i++){
        
        int t1 = Min(dpMin[0], dpMin[1]) + map[i][0];
        int t2 = Min(dpMin[0], dpMin[1], dpMin[2]) + map[i][1];
        int t3 = Min(dpMin[1], dpMin[2]) + map[i][2];
        dpMin[0] = t1; dpMin[1] = t2; dpMin[2] = t3;

        t1 = Max(dpMax[0], dpMax[1]) + map[i][0];
        t2 = Max(dpMax[0], dpMax[1], dpMax[2]) + map[i][1];
        t3 = Max(dpMax[1], dpMax[2]) + map[i][2];
        dpMax[0] = t1; dpMax[1] = t2; dpMax[2] = t3;
    }
    printf("%d %d\n", dpMax[1], dpMin[1]);
}