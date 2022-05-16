#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct Person{
    string name;
    int score;
};

struct cmp{
    bool operator() (Person a, Person b){
        
        if(a.score > b.score){
            return false;
        }
        else if(a.score == b.score){
            if(a.name.compare(b.name) < 0)
            {
                return false;
            }
            else{
                return true;
            }
        }
        else{
            return true;
        }
    }
};

int main()
{
    int N;
    priority_queue< Person, vector<Person>, cmp > pq;

    cin >> N;
    for(int i=0; i<N; i++){
        Person t;
        cin >> t.name >> t.score;

        pq.push(t);
    }

    cout << pq.top().name << "\n";
}