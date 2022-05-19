#include <stdio.h>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

struct Homework{
    int score;
    int day;
};

struct cmp{

    bool operator()(Homework a, Homework b){
        if( a.score < b.score) return false;
        else if(a.score == b.score){
            return a.day < b.day;
        }
        else{
            return true;
        }
    }
};

bool compare(Homework a, Homework b){
    if( a.day < b.day) return true;
    else return false;
}

int main()
{
    vector<Homework> hw;
    priority_queue< Homework, vector<Homework>, cmp> pq;

    int N;
    scanf("%d", &N);

    for(int i=0; i<N; i++){
        Homework t;
        scanf("%d %d", &t.day, &t.score);
        hw.push_back(t);
    }
    sort(hw.begin(), hw.end(), compare);

    int day = 1; int hwindex = 0;
    while(1){
        while(hwindex < hw.size() && hw[hwindex].day <= day){
            pq.push(hw[hwindex]);
            hwindex++;
        }
        while(pq.size() > day){
            pq.pop();
        }
        day++;

        if(hwindex >= hw.size()) break;
    }

    int sum = 0;
    while(!pq.empty()){
        sum = sum + pq.top().score;
        pq.pop();
    }

    printf("%d\n", sum);
}