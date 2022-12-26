#include <stdio.h>

int H, W;
int h[500];

void input()
{
    scanf("%d %d", &H, &W);
    for(int i=0l; i<W; i++){
        scanf("%d", &h[i]);
    }
}

int answer()
{
    int sum = 0;
    int maxH = h[0];
    bool check[500] = {false,};
    for(int i=1; i<W; i++){
        if( maxH <= h[i] )
        {
            for(int j=i-1; ; j--)
            {
                if(h[j] == maxH) break;
                sum = sum + (maxH-h[j]);

                check[j] = true;
            }
            maxH = h[i];
        }
    }

    maxH = h[W-1];
    for(int i=W-2; i>=0; i--){
        if( maxH <= h[i] )
        {
            for(int j=i+1; ; j++)
            {
                if(check[j] == true ) continue;
                if(h[j] == maxH) break;
                sum = sum + (maxH-h[j]);
            }
            maxH = h[i];
        }
    }
    
    return sum;
}

int main()
{
    input();
    printf("%d\n", answer());
}