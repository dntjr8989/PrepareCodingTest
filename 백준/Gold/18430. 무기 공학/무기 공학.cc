#include <stdio.h>

int N, M;
int wood[5][5];
int max = 0;

void func(int check[5][5], int sum, int y, int x)
{
    if(y >= N)
    {
        if(sum > max) {
            max = sum;
        }
        return;
    }
    int tempcheck[5][5] = {0,};
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++) tempcheck[i][j] = check[i][j];
    }
    if(x >= M)
    {
        func(check, sum, y+1, 0);
    }
    else
    {
        func(check, sum, y, x+1);
        //ㄱ
        if(x-1 >= 0 && y+1 < N)
        {
            if(tempcheck[y][x-1] == 0 && tempcheck[y][x] == 0 && tempcheck[y+1][x] == 0)
            {
                tempcheck[y][x-1] = 1; tempcheck[y+1][x] = 1; tempcheck[y][x] = 2;
                func(tempcheck, sum+wood[y][x-1]+wood[y+1][x]+2*wood[y][x], y, x+1);
                tempcheck[y][x-1] = 0; tempcheck[y+1][x] = 0; tempcheck[y][x] = 0;
            }
        }
                
        //ㄴ
        if(x+1 < M && y-1 >= 0)
        {
            if(tempcheck[y][x+1] == 0 && tempcheck[y-1][x] == 0 && tempcheck[y][x] == 0)
            {
                tempcheck[y-1][x] = 1; tempcheck[y][x+1] = 1; tempcheck[y][x] = 2;
                func(tempcheck, sum+wood[y-1][x]+wood[y][x+1]+2*wood[y][x], y, x+1);
                tempcheck[y-1][x] = 0; tempcheck[y][x+1] = 0; tempcheck[y][x] = 0;
            }
        }

        if(y-1 >= 0 && x-1 >= 0)
        {
            if(tempcheck[y-1][x] == 0 && tempcheck[y][x-1] == 0 && tempcheck[y][x] == 0)
            {
                tempcheck[y-1][x] = 1; tempcheck[y][x-1] = 1; tempcheck[y][x] = 2;
                func(tempcheck, sum+wood[y-1][x]+wood[y][x-1]+2*wood[y][x], y, x+1);
                tempcheck[y-1][x] = 0; tempcheck[y][x-1] = 0; tempcheck[y][x] = 0;
            }
        }

        if(x+1 < M && y+1 < N)
        {
            if(tempcheck[y][x+1] == 0 && tempcheck[y][x] == 0 && tempcheck[y+1][x] == 0)
            {
                tempcheck[y][x+1] = 1; tempcheck[y+1][x] = 1; tempcheck[y][x] = 2;
                func(tempcheck, sum+wood[y][x+1]+wood[y+1][x]+2*wood[y][x], y, x+1);
                tempcheck[y][x+1] = 0; tempcheck[y+1][x] = 0; tempcheck[y][x] = 0;
            }
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%d", &wood[i][j]);
        }
    }
    int check[5][5] = {0, };
    func(check, 0, 0, 0);

    printf("%d\n", max);
}