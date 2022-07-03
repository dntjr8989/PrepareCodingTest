#include <stdio.h>

int N;
int student[401][5];
int studentPosition[401][2];
int map[20][20] = {0,};
bool check[401] = {false,};
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

void input()
{
    scanf("%d", &N);
    for(int i=0; i<N*N; i++){
        for(int j=0; j<5; j++){
            scanf("%d", &student[i][j]);
        }
    }
    return;
};

void position(int index)
{
    //어느 칸에 넣어야 할 지 검사
    int maxCnt = -1; int maxBlank = -1; int maxy = N; int maxx = N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(map[i][j] != 0) continue;
            int cnt = 0; int blank = 0;
            for(int k=0; k<4; k++){
                int ty = i + dy[k]; int tx = j + dx[k];
                if(ty < 0 || ty >= N || tx < 0 || tx >= N) continue;

                if(map[ty][tx] == 0) blank++;
                else{
                    for(int l=1; l<=4; l++){
                        if(map[ty][tx] == student[index][l]){cnt++; break;}
                    }
                }
            }
            if(cnt > maxCnt) {maxCnt = cnt; maxBlank = blank; maxy = i; maxx = j;}
            else if(cnt == maxCnt){
                if(blank > maxBlank){
                    maxCnt = cnt; maxBlank = blank; maxy = i; maxx = j;
                }
                else if(blank == maxBlank){
                    if(i < maxy){
                        maxCnt = cnt; maxBlank = blank; maxy = i; maxx = j;
                    }
                    else if(i == maxy){
                        if(j < maxx){
                            maxCnt = cnt; maxBlank = blank; maxy = i; maxx = j;
                        }
                    }
                }
            }
        }
    }
    map[maxy][maxx] = student[index][0];
    studentPosition[index][0] = maxy; studentPosition[index][1] = maxx;
}

int sum(){
    int sum = 0;
    for(int i=0; i<N*N; i++){
        int y = studentPosition[i][0]; int x = studentPosition[i][1];

        int cnt = 0;
        for(int j=0; j<4; j++){
            int ty = y+dy[j]; int tx = x+dx[j];
            if(ty < 0 || ty >= N || tx < 0 || tx >= N) continue;

            for(int k=1; k<=4; k++){
                if(student[i][k] == map[ty][tx]){cnt++; break;}
            }
        }
        if(cnt == 0) sum = sum + 0;
        else if(cnt == 1) sum = sum + 1;
        else if(cnt == 2) sum = sum + 10;
        else if(cnt == 3) sum = sum + 100;
        else sum = sum + 1000;
    }
    return sum;
}

int solve()
{
    for(int i=0; i<N*N; i++){
        //어디에 학생을 배치해야할 지 결정
        position(i);
    }
    //만족도 합 구하기
    return sum();
};

int main()
{
    //입력
    input();

    //
    printf("%d\n", solve());
}