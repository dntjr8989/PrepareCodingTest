#include <stdio.h>
#include <string.h>

using namespace std;

char map[100][102];
char word[82];

int check[100][100][80];
int N, M, K;

int findWord(int y, int x, int index){
    //종료 조건
    
    if(index == strlen(word)-1 && map[y][x] == word[index]){
        return 1;
    }
    if(map[y][x] != word[index])
    {
        return 0;
    }
    if(check[y][x][index] != -1) return check[y][x][index];

    //다음 단어 이동
    int sum = 0;
    for(int i=1; i<=K; i++)
    {
        //위
        if(y-i >= 0){
            sum = sum + findWord(y-i, x, index+1);
        }
        //아래
        if(y+i < N){
            sum = sum + findWord(y+i, x, index+1);
        }
        //오른쪽
        if(x+i < M){
            sum = sum + findWord(y, x+i, index+1);
        }
        //왼쪽
        if(x-i >= 0){
            sum = sum + findWord(y, x-i, index+1);
        }
    }
    check[y][x][index] = sum;

    return sum;
}

int main()
{
    //입력
    scanf("%d %d %d", &N, &M, &K);
    for(int i=0; i<N; i++)
    {
        scanf("%s", map[i]);
    }
    scanf("%s", word);

    //check 함수 초기화
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            for(int k=0; k<strlen(word); k++)
            {
                check[i][j][k] = -1;
            }
        }
    }

    //단여 찾기
    int answer = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            //처음 글자가 있는 칸 찾았으면
            if(word[0] == map[i][j]){
                answer = answer + findWord(i, j, 0);
            }
        }
    }
    //출력
    printf("%d\n", answer);

    return 0;
}