#include <stdio.h>

int N, balloon[1000];
bool check[1000] = {false,};
int cnt = 0;
int index = 0;

void input()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &balloon[i]);
    }
}

void popballoon()
{
    while(cnt < N-1)
    {
        check[index] = true;
        printf("%d ", index+1);
        cnt++;
        
        int t = balloon[index];
        if(t < 0)
        {
            for(int i=0; i<-t; i++)
            {
                index--;
                if(index < 0) index = N-1;
                if(check[index] == true)
                {
                    i--; continue;
                }
            }
        }
        else{
            for(int i=0; i<t; i++)
            {
                index++;
                if(index > N-1) index = 0;
                if(check[index] == true)
                {
                    i--; continue;
                }
            }
        }
    }
    printf("%d\n", index+1);
}

int main()
{
    input();
    popballoon();
}