#include <stdio.h>

int kingY, kingX;
int stoneY, stoneX;

void kingMove(int dy, int dx)
{
    if(kingY + dy >= 9 || kingY + dy <= 0 || kingX + dx >= 9 || kingX + dx <= 0)
    {
        return;
    }
    else if(kingY+dy == stoneY && kingX+dx == stoneX)
    {
        if(stoneY + dy >= 9 || stoneY + dy <= 0 || stoneX + dx >= 9 || stoneX + dx <= 0)
        {
            return;
        }
        else{
            kingY = kingY + dy; kingX = kingX + dx; stoneY = stoneY + dy; stoneX = stoneX + dx;
        }
    }
    else
    {
        kingY = kingY + dy; kingX = kingX + dx;
    }
}

int main()
{
    int n;
    char input[8];
    scanf("%s", input);
    kingX = input[0]-'A'+1; kingY = input[1]-'0';
    scanf("%s", input);
    stoneX = input[0]-'A'+1; stoneY = input[1]-'0';
    scanf("%d", &n);

    for(int i=1; i<=n; i++)
    {
        scanf("%s", input);
        if(input[0] == 'B')
        {
            kingMove(-1, 0);
        }
        else if(input[0] == 'T')
        {
            kingMove(1, 0);
        }
        else if(input[0] == 'L')
        {
            if(input[1] == '\0')
            {
                kingMove(0, -1);
            }
            else if(input[1] == 'T')
            {
                kingMove(1, -1);
            }
            else if(input[1] == 'B')
            {
                kingMove(-1, -1);
            }
        }
        else if(input[0] == 'R')
        {
            if(input[1] == '\0')
            {
                kingMove(0, 1);
            }
            else if(input[1] == 'T')
            {
                kingMove(1, 1);
            }
            else if(input[1] == 'B')
            {
                kingMove(-1, 1);
            }
        }
        
    }

    printf("%c%c\n", kingX+'A'-1, kingY+'0');
    printf("%c%c\n", stoneX+'A'-1, stoneY+'0');
}