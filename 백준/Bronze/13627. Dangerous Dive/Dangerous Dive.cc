#include <stdio.h>

int main()
{
    bool check[100001] = {false,};
    int N, R;
    scanf("%d %d", &N, &R);

    for(int i=0; i<R; i++){
        int t;
        scanf("%d", &t);
        check[t] = true;
    }

    if(N == R){
        printf("*\n");
    }
    else
    {
        for(int i=1; i<=N; i++){
            if(check[i] == false){
                printf("%d ", i);
            }
        }
        printf("\n");
    }
}