#include <stdio.h>
#include <queue>

using namespace std;

int main()
{
    int N;
    priority_queue<int, vector<int>, greater<int> > pq; 
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        int t; scanf("%d", &t);
        pq.push(t);
    }
    int answer=0; int sum=0;

    for(int i=0; i<N; i++){
        sum = sum + pq.top(); pq.pop();
        answer = answer+sum;
    }

    printf("%d\n", answer);
}