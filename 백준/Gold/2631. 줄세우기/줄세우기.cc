#include <stdio.h>

int main()
{
    int N;
    int num[200];
    
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &num[i]);
    }
    int array[200];
    array[0] = num[0];
    int arrayn = 1; 
    for(int i=1; i<N; i++){

        int s = 0; int e = arrayn;
        while(s < e){
            int mid = (s+e)/2;
            if(array[mid] < num[i]){
                s = mid+1;
            }
            else{
                e = mid;
            }
        }
        if(e == arrayn) arrayn++;
        array[e] = num[i];
    }

    printf("%d\n", N-arrayn);
}