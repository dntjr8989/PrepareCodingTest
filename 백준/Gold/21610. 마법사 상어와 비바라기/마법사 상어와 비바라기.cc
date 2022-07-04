#include <stdio.h>
#include <vector>

using namespace std;

int N, M;
int A[50][50];
bool cloud[50][50] = {false,};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1}; 

int count(int y, int x){
    int cnt = 0;
    if(y-1 >= 0 && x-1 >= 0){
        if(A[y-1][x-1] > 0) cnt++;
    }

    if(y-1 >= 0 && x+1 < N){
        if(A[y-1][x+1] > 0) cnt++;
    }

    if(y+1 < N && x-1 >= 0){
        if(A[y+1][x-1] > 0) cnt++;
    }

    if(y+1 < N && x+1 < N){
        if(A[y+1][x+1] > 0) cnt++;
    }
    return cnt;
};

void move(int d, int s){
    bool moveCloud[50][50] = {false,};
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int y = ((i+dy[d]*s)%N+N)%N; int x = ((j+dx[d]*s)%N+N)%N;
            moveCloud[y][x] = cloud[i][j];
        }
    }

    //구름 비 내리기
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(moveCloud[i][j] == true){
                A[i][j] = A[i][j]+1;
            }
        }
    }
    //물 복사
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(moveCloud[i][j] == true){
                A[i][j] = A[i][j]+count(i,j);
            }
        }
    }
    //구름 생성
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(A[i][j] >= 2){
                if(moveCloud[i][j] == false){
                    cloud[i][j] = true;
                    A[i][j] = A[i][j] - 2;
                }
                else{
                    cloud[i][j] = false;
                }
            }
            else{
                cloud[i][j] = false;
            }
        }
    }
};

int main()
{
    scanf("%d %d", &N, &M);

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &A[i][j]);
        }
    }
    
    cloud[N-2][0] = true; cloud[N-2][1] = true; cloud[N-1][0] = true; cloud[N-1][1] = true;
    
    for(int i=0; i<M; i++){
        int d, s;
        scanf("%d %d", &d, &s);
        move(d-1, s);
    }

    int sum = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            sum = sum + A[i][j];
        }
    }
    printf("%d\n", sum);
}