#include <stdio.h>

int N, K;
int weight[9];
int check[257][401];
int complete;

int func(int kit, int w){
    if(kit == complete){
        if(w >= 0) return 1;
        else return 0;
    }
    if(w < 0){
        return 0;
    }

    int sum = 0;
    int tempKit = kit; int t = 1;
    for(int i=1; i<=N; i++){
        if((tempKit & 1) == 0){
            sum = sum + func(kit+t, w+weight[i]-K);
        }
        t = t * 2;
        tempKit = tempKit >> 1;
    }

    return sum;
}

int main()
{
    for(int i=0; i<=256; i++){
        for(int j=0; j<=400; j++){
            check[i][j] = -1;
        }
    }
    scanf("%d %d", &N, &K);
    complete = 1;
    for(int i=1; i<=N; i++){
        scanf("%d", &weight[i]);
        complete = complete * 2;
    }
    complete--;

    printf("%d\n", func(0, 0));
}