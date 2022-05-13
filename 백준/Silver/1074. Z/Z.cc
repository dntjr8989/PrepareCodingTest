#include <iostream>
#include <cmath>

using namespace std;

int divConquer(int N, int r, int c){

    if(N == 0) return 1;

    //(r, c)가 몇 사분면에 위치하는 지 파악
    int m = (int)pow(2,N-1)-1;
    
    //1사분면
    if(c > m && r <= m) return (int)pow(2,2*N-2) + divConquer(N-1, r, c%((int)pow(2,N-1)));
    //2사분면
    else if(c <= m && r <= m) return divConquer(N-1, r, c);
    //3사분면
    else if(c <= m && r > m) return (int)pow(2,2*N-2)*2 + divConquer(N-1, r%((int)pow(2,N-1)), c);
    //4사분면
    else return (int)pow(2,2*N-2)*3 + divConquer(N-1, r%((int)pow(2,N-1)), c%((int)pow(2,N-1)));
}

int main()
{
    int N, r, c;
    cin >> N >> r >> c;

    cout << divConquer(N, r, c)-1 << endl;
}