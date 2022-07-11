#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int compare1(int a, int b){
    if(a > b) return true;
    else return false;
};


int compare2(int a, int b){
    if(a >= b) return false;
    else return true;
};

int main()
{
    vector< int > A;
    vector< int > B;
    int N;

    scanf("%d", &N);
    for(int i=0; i<N; i++){
        int t;
        scanf("%d", &t);
        A.push_back(t);
    }

    for(int i=0; i<N; i++){
        int t;
        scanf("%d", &t);
        B.push_back(t);
    }

    sort(A.begin(), A.end(), compare1);

    sort(B.begin(), B.end(), compare2);

    int sum = 0;
    for(int i=0; i<N; i++){
        sum = sum + A[i]*B[i];
    }

    printf("%d\n", sum);
}