#include <stdio.h>

int N, M, K;
int noteBook[40][40] = {0,};

bool attach(int R, int C, int sticker[10][10])
{
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(i+R-1 >= N) continue;
            if(j+C-1 >= M) continue;
            bool flag = true;
            for(int k=0; k<R; k++){
                for(int m=0; m<C; m++){
                    if(sticker[k][m] == 1)
                    {
                        if(noteBook[k+i][m+j] == 1)
                        {
                            flag = false; break;
                        }
                    }
                }
                if(flag == false) break;
            }
            if(flag == true)
            {
                for(int k=0; k<R; k++){
                    for(int m=0; m<C; m++){
                        if(sticker[k][m] == 0) continue;
                        noteBook[k+i][m+j] = sticker[k][m]; 
                    }
                }
                return true;
            }
        }
    }
    return false;
}

void rotate(int *R, int *C, int sticker[10][10])
{
    int tempSticker[10][10];
    for(int i=0; i<*C; i++){
        for(int j=0; j<*R; j++){
            tempSticker[i][j] = sticker[*R-j-1][i];
        }
    }
    int t;
    t = *R;
    *R = * C;
    *C = t;
    for(int i=0; i<*R; i++){
        for(int j=0; j<*C; j++){
            sticker[i][j] = tempSticker[i][j];
        }
    }
}

int main()
{
    scanf("%d %d %d", &N, &M, &K);
    
    for(int i=0; i<K; i++){
        int R, C;
        int sticker[10][10];
        scanf("%d %d", &R, &C);
        for(int j=0; j<R; j++){
            for(int k=0; k<C; k++) scanf("%d", &sticker[j][k]);
        }
        
        for(int j=0; j<4; j++){
            if(!attach(R, C, sticker))
            {
                rotate(&R, &C, sticker);
            }
            else{
                break;
            }
        }
    }

    int cnt = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(noteBook[i][j] == 1) cnt++;
        }
    }
    printf("%d\n", cnt);
}