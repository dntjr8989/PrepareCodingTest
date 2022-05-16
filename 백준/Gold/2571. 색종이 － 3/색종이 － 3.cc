#include <stdio.h>

int main()
{
    int N;
    bool paper[100][100] = {false,};
    
    scanf("%d", &N);

    for(int i=0; i<N; i++){
        int t1, t2;
        scanf("%d %d", &t1, &t2);

        for(int j=t2; j<t2+10; j++){
            for(int k=t1; k<t1+10; k++){
                paper[j][k] = true;
            }
        }
    }
    int max = -1;
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            if(paper[i][j] == false) continue;
            int minwidth = 10000;
            for(int k=i; k<100; k++){
                int cnt = 0;
                for(int l=j; l<100; l++){
                    if(paper[k][l] == true) cnt++;
                    else break;
                }
                if(minwidth > cnt) minwidth = cnt;
                if(minwidth == 0) break;
                if(minwidth*(k-i+1) > max) max = minwidth*(k-i+1);
            }
        }
    }

    printf("%d\n", max);
}