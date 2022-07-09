#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n;
    int a, b;
    int m;
    vector<int> relation[101];

    scanf("%d", &n);
    scanf("%d %d", &a, &b);
    scanf("%d", &m);

    for(int i=0; i<m; i++){
        int y; int x;
        scanf("%d %d", &y, &x);
        relation[y].push_back(x);
        relation[x].push_back(y);
    }

    queue< pair<int ,int > > q;
    bool check[101] = {false,};
    q.push(make_pair(a, 0)); check[a] = true;
    while(!q.empty()){
        int p = q.front().first; int t = q.front().second;
        q.pop();

        if(p == b){
            printf("%d\n", t);
            return 0;
        }
        for(int i=0; i<relation[p].size(); i++){
            if(check[relation[p][i]] == true) continue;
            
            q.push(make_pair(relation[p][i], t+1));
            check[relation[p][i]] = true;
        }
    }
    printf("-1\n");
}