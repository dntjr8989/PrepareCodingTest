#include <stdio.h>

int N, M;
char board[51][51];
char chess[8][8];

void divBoard(int y, int x){
    for(int i=y; i<y+8; i++){
        for(int j=x; j<x+8; j++){
            chess[i-y][j-x] = board[i][j];
        }
    }
}
int paint()
{
    char t[8][8] = { {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
                     {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
                     {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
                     {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
                     {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
                     {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
                     {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
                     {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'}, };

    char t1[8][8] = { {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
                     {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
                     {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
                     {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
                     {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
                     {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
                     {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
                     {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'} };    

    int cnt1 = 0;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(chess[i][j] != t[i][j]) cnt1++;
        }
    }


    int cnt2 = 0;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(chess[i][j] != t1[i][j]) cnt2++;
        }
    }
    return (cnt1 > cnt2) ? cnt2 : cnt1;
}

int main()
{
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        scanf("%s", board[i]);
    }
    int min = 65;

    for(int i=0; i<=N-8; i++){
        for(int j=0; j<=M-8; j++){
            //board 8*8 나누기
            divBoard(i, j);

            //칠할 정사각형 갯수
            int t = paint();

            if(min > t) min = t;
        }
    }
    printf("%d\n", min);
}