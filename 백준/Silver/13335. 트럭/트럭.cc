#include <stdio.h>
#include <queue>

using namespace std;

int n, w, L;
int truck[1000];

void input()
{
    scanf("%d %d %d", &n, &w, &L);
    for(int i=0; i<n; i++){
        scanf("%d", &truck[i]);
    }
}

int main()
{
    input();

    queue< pair<int, int> > q;
    int sum = 0;
    int time; int index = 0;
    for(time=0; ; time++){
        
        if(q.size() == 0 && index >= n) break;

        if(q.size() > 0 && q.front().second+w == time) {sum = sum - q.front().first; q.pop();}

        if(q.size() < w)
        {
            if(index >= n) continue;
            if(sum+truck[index] <= L)
            {
                sum = sum + truck[index];
                q.push(make_pair(truck[index], time));
                index++;
            }
        }
    }

    printf("%d\n", time);
}