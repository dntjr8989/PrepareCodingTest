#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int N, D;
vector< pair < int, int > > shortcut[10001];

int BFS(int pos)
{
    queue< pair<int, int> > q;
    q.push(make_pair(0, 0));
    
    int min = D;
    while(!q.empty())
    {
        int p = q.front().first; int d = q.front().second;
        q.pop();
        if(p == D)
        {
            if(min > d) min = d;
            continue;
        }
        else if(p > D) continue;

        q.push(make_pair(p+1, d+1));
        for(int i=0; i<shortcut[p].size(); i++)
        {
            q.push(make_pair(shortcut[p][i].first, d+shortcut[p][i].second));
        }
    }
    return min;
}

int main()
{
    scanf("%d %d", &N, &D);

    for(int i=0; i<N; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        shortcut[a].push_back(make_pair(b, c));
    }

    printf("%d\n", BFS(0));
}