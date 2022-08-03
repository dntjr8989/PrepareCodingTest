#include <stdio.h>

int N;
int checkPoint[100000][2];
int d[100000];

int dist(int y1, int x1, int y2, int x2)
{
    int dy = y1-y2;
    if(dy < 0) dy = -dy;

    int dx = x1-x2;
    if(dx < 0) dx = -dx; 

    return dy+dx;
}

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d %d", &checkPoint[i][0], &checkPoint[i][1]);
    }

    int sum = 0;
    for(int i=0; i<N-1; i++){
        d[i] = dist(checkPoint[i][0], checkPoint[i][1], checkPoint[i+1][0], checkPoint[i+1][1]);
        sum = sum + d[i];
    }

    int min = sum;
    for(int i=1; i<N-1; i++){
        if(sum-(d[i-1]+d[i])+dist(checkPoint[i-1][0], checkPoint[i-1][1], checkPoint[i+1][0], checkPoint[i+1][1]) < min)
        {
            min = sum-(d[i-1]+d[i])+dist(checkPoint[i-1][0], checkPoint[i-1][1], checkPoint[i+1][0], checkPoint[i+1][1]);
        }    
    }
    printf("%d\n", min);
}