#include <iostream>
#include <queue>
#include <string>

using namespace std;

int N, M;
bool map[1000][1000];
bool check[1000][1000][2] = {false,};

struct Position{
    int y, x;
    int cnt;
    bool wall;
    Position(int Y, int X, int C, bool W) : y(Y), x(X), cnt(C), wall(W) {}; 
};

void input()
{
    cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> N >> M;

    for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < temp.size(); j++)
		{
			map[i][j] = temp[j] - '0';
		}
	}	
}

int BFS()
{
    queue<Position> q;
    q.push(Position(0, 0, 1, false));
    check[0][0][0] = true;
    
    while( !q.empty() )
    {
        Position temp = q.front();
        q.pop();

        if(temp.y == N-1 && temp.x == M-1)
        {
            return temp.cnt;
        }

        int dy[4] = {1, -1, 0, 0};
        int dx[4] = {0, 0, 1, -1};

        for(int i=0; i<4; i++){

            int ty = temp.y + dy[i]; int tx = temp.x + dx[i];
            if(ty >= N || ty < 0 || tx >= M || tx < 0) continue;
            if(map[ty][tx] == 1)
            {
                if(temp.wall == false && check[ty][tx][1] == false)
                {
                    q.push(Position(ty, tx, temp.cnt+1, true));
                    check[ty][tx][1] = true;
                }
            }
            else{
                
                if(check[ty][tx][temp.wall] == true) continue;

                q.push(Position(ty, tx, temp.cnt+1, temp.wall));
                check[ty][tx][temp.wall] = true;
            }
        }
    }

    return -1;
}

int main()
{
    input();
    printf("%d\n", BFS());
}