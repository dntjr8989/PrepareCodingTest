#include <stdio.h>
#include <vector>
#include <queue>
#define INF 3100000

using namespace std;

struct cmp
{
	bool operator()(const pair<int, int>& a, const pair<int, int>& b)
	{
		if (a.second != b.second)
			return a.second > b.second;
		else
			return a.first < b.first;
	}
};

int main()
{
    int V, E;
    int K;
    vector< pair<short, short> > w[20001];
    int dis[20001];

    scanf("%d %d", &V, &E);
    scanf("%d", &K);

    for(int i=1; i<=V; i++) dis[i] = INF;
    for(int i=0; i<E; i++){
        short t1, t2, t3;
        scanf("%hd %hd %hd", &t1, &t2, &t3);
        w[t1].push_back(make_pair(t2, t3));
    }
    dis[K] = 0;

    priority_queue<pair<int, int>, vector< pair<int, int> >, cmp> q;
    q.push(make_pair(K, 0));

    while(!q.empty()){
        
        int current = q.top().first;
		int distance = q.top().second;
		q.pop();

        //dist갱신
        for(int i=0; i<w[current].size(); i++){
            int next_node = w[current][i].first;
			int dist_to_next_node = w[current][i].second;

            if(dis[next_node] > dist_to_next_node + distance){
                dis[next_node] = dist_to_next_node + distance;
				q.push(make_pair(next_node, dis[next_node]));
            }
        }
    }

    for(int i=1; i<=V; i++){
        if(dis[i] >= INF) printf("INF\n");
        else printf("%d\n", dis[i]);
    }
}