#include <iostream>

using namespace std;

int main()
{
     int dp[41][2]; //dp[A][0] : A경우 0이 출력된 횟수, dp[A][1] : A경우 1이 출력 된 횟수
     int T;
     cin >> T;
     for(int i=0; i<41; i++){
        dp[i][0] = -1; dp[i][1] = -1;
     }
     dp[0][0] = 1; dp[0][1] = 0; dp[1][0] = 0; dp[1][1] = 1;
     for(int tc=1; tc<=T; tc++){
        int N;
        cin >> N;

        //이미 구한 것 이라면 출력
        if(dp[N][0] != -1 && dp[N][1] != -1) {cout << dp[N][0] << " " << dp[N][1] << endl; continue;}

        //dp구하기
        for(int i=2; i<=N; i++){
            dp[i][0] = dp[i-1][0] + dp[i-2][0];
            dp[i][1] = dp[i-1][1] + dp[i-2][1];
        }
        cout << dp[N][0] << " " << dp[N][1] << endl;
    }
}