#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> A;
vector<int> B;
int check[2000][2000];

int Max(int a, int b){
    if(a > b) return a;
    else return b;
}

int dp(int indexA, int indexB){
    //규칙3
    if(indexA == N || indexB == N){
        return 0;
    }

    if(check[indexA][indexB] != -1) return check[indexA][indexB];

    //규칙1
    int max = -1;
    max = Max(max, dp(indexA+1, indexB));
    max = Max(max, dp(indexA+1, indexB+1));
    //규칙2
    if(A[indexA] > B[indexB]) max=Max(max, dp(indexA, indexB+1)+B[indexB]);

    check[indexA][indexB] = max;

    return max;
}

int main()
{
    cin >> N;
    for(int i=0; i<N; i++){
        int t;
        cin >> t; A.push_back(t); 
    }

    for(int i=0; i<N; i++){
        int t;
        cin >> t; B.push_back(t);
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) check[i][j] = -1;
    }
    cout << dp(0, 0);
}