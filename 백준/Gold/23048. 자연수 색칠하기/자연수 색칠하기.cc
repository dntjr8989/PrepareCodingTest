#include <stdio.h>

int main()
{
    int N;
    int cnt;
    int check[500001] = {0,};
    scanf("%d", &N);

    cnt = 1;
    check[1] = cnt;

    for(int i=2; i<=N; i++){
        if(check[i] == 0){
            cnt++;
            int j=1;
            while(i*j <= N){
                check[i*j] = cnt;
                j++;
            }
        }
    }
    printf("%d\n", cnt);
    for(int i=1; i<=N; i++){
        printf("%d ", check[i]);
    }
}