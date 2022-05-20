#include <stdio.h>
#include <queue>

using namespace std;

int small[9];
priority_queue<int, vector<int>, greater<int> > pq;

bool func(int index, int cnt, int sum, int check){

    if(cnt == 7){
        if(sum == 100){
            for(int i=0; i<9; i++){
                if( (check>>i) & 1){
                    pq.push(small[i]);
                }
            }
            return true;
        }
        return false;
    }
    if(index >= 9) return false;
    if(sum > 100) return false;
    //index번째 난쟁이 선택
    bool flag = func(index+1, cnt+1, sum+small[index], check+(1<<index));
    if(flag == true) return flag;
    //index번째 난쟁이 선택 X
    return func(index+1, cnt, sum, check);
}

int main()
{
    for(int i=0; i<9; i++){
        scanf("%d", &small[i]);
    }

    func(0, 0, 0, 0);

    for(int i=0; i<7; i++){
        printf("%d\n", pq.top());
        pq.pop();
    }
}