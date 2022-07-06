#include <iostream>
#include <string.h>

using namespace std;

int dp[100][20][3];

char scroll[21], devil[101], angel[101];

int func(int a, int b, int c)
{
    if(a == strlen(devil)){
        if(b == strlen(scroll)){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(b == strlen(scroll)) return 1;
    if(dp[a][b][c] != -1) return dp[a][b][c];

    int cnt = 0;
    if(scroll[b] == devil[a] && c != 1)
    {
        cnt = cnt + func(a+1, b+1, 1);
    }
    if(scroll[b] == angel[a] && c != 2){
        cnt = cnt + func(a+1, b+1, 2);
    }
    
    cnt = cnt + func(a+1, b, c);
    dp[a][b][c] = cnt;

    return cnt;
}

int main()
{
    cin >> scroll;
    cin >> devil;
    cin >> angel;

    for(int i=0; i<100; i++)
    {
        for(int j=0; j<20; j++){
            dp[i][j][0] = -1; dp[i][j][1] = -1; dp[i][j][2] = -1;
        }
    }

    printf("%d\n", func(0, 0, 0));
}