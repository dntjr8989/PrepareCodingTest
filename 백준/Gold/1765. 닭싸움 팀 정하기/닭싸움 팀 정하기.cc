#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
int m;

struct Relation{
    vector<int> f;
    vector<int> e;
};

Relation student[1001];
bool check[1001] = {false,};

void BFS(int s)
{
    queue<int> q;
    check[s] = true;
    q.push(s);

    while(!q.empty())
    {
        int t = q.front();
        q.pop();

        for(int i=0; i<student[t].f.size(); i++)
        {
            if(check[student[t].f[i]]) continue;
            q.push(student[t].f[i]);
            check[student[t].f[i]] = true;
        }


        for(int i=0; i<student[t].e.size(); i++)
        {
            int temp = student[t].e[i];
            for(int j=0; j<student[temp].e.size(); j++)
            {
                if(check[student[temp].e[j]]) continue;
                q.push(student[temp].e[j]);
                check[student[temp].e[j]] = true;
            }
        }
    }    
}


int main()
{
    cin >> n;
    cin >> m;

    for(int i=0; i<m; i++)
    {
        char a; int b, c;
        cin >> a >> b >> c;

        if(a == 'E')
        {
            student[b].e.push_back(c);
            student[c].e.push_back(b);
        }
        else{
            student[b].f.push_back(c);
            student[c].f.push_back(b);
        }
    }
    int cnt = 0;
    for(int i=1; i<=n; i++){
        if(check[i] == false)
        {
            BFS(i);
            cnt++;
        }
    }
    cout << cnt << endl;
}