#include <stdio.h>
#include <queue>

using namespace std;

int main()
{
    int N;

    priority_queue<int> pq; 
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        int x;
        scanf("%d", &x);
        //0 : 가장 큰 값 출력
        if(x == 0){
            if(!pq.empty()){
                printf("%d\n", pq.top());
                pq.pop(); 
            }
            else{
                printf("0\n");
            }
        }
        //추가 
        else{
            pq.push(x);
        }
    }
}