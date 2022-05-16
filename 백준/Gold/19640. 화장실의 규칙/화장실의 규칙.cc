#include <stdio.h>
#include <queue>

using namespace std;

int N, M, K;

struct Person{
    int D;
    int H;
    int index;
};

struct cmp{
    bool operator() (Person a, Person b){
        if(a.D < b.D) return true;
        else if(a.D == b.D){
            if(a.H < b.H) return true;
            else if(a.H == b.H){
                return ((a.index%M) > (b.index%M));
            }
            else return false;
        }
        else return false;
    }
};

int main()
{
    scanf("%d %d %d", &N, &M, &K);
    
    vector< Person > p;
    for(int i=0; i<N; i++){
        Person t;
        scanf("%d %d", &t.D, &t.H);
        t.index = i;
        p.push_back(t);
    }
    priority_queue<Person, vector<Person>, cmp > pq;

    for(int i=0; i<M; i++){
        if(p.size() == i) break;
        pq.push(p[i]);
    }

    int cnt = 0;
    while(1){
        Person t = pq.top();
        pq.pop();
        if(t.index == K){
            printf("%d\n", cnt);
            break;
        }
        if(t.index+M <= N-1){
            pq.push(p[t.index+M]);
        }
        cnt++;
    }
}