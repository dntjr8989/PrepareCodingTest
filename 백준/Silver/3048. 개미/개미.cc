#include <stdio.h>

int N1; int N2;
char antGroup1[27];
char antGroup2[27];
char ant[27][2];
int T;

void reverse()
{
    char tempGroup[27];
    for(int i=0; i<N1; i++){
        tempGroup[N1-i-1] = antGroup1[i];
    }
    for(int i=0; i<N1; i++){
        antGroup1[i] = tempGroup[i];
    }
};

void sum()
{
    for(int i=0; i<N1; i++){
        ant[i][0] = antGroup1[i]; ant[i][1] = 'R';
    }
    for(int i=0; i<N2; i++){
        ant[i+N1][0] = antGroup2[i]; ant[i+N1][1] = 'L';
    }
};

int main()
{
    scanf("%d %d", &N1, &N2);
    scanf("%s", antGroup1);
    scanf("%s", antGroup2);
    scanf("%d", &T);

    reverse();
    sum();

    for(int i=0; i<T; i++){
        bool revise[27] = {false,};
        for(int j=0; j<N1+N2-1; j++){
            if(ant[j][1] == 'R' && ant[j+1][1] == 'L')
            {
                revise[j] = true;
            }
        }
        for(int j=0; j<N1+N2-1; j++){
            if(revise[j] == true)
            {
                char t1 = ant[j][0]; char t2 = ant[j][1];
                ant[j][0] = ant[j+1][0]; ant[j][1] = ant[j+1][1];
                ant[j+1][0] = t1; ant[j+1][1] = t2; 
            }
        }
    }

    for(int i=0; i<N1+N2; i++){
        printf("%c", ant[i][0]);
    }
    printf("\n");
}