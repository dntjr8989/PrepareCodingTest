#include <stdio.h>
#include <queue>

using namespace std;

int W, H;
int map[100][100];

struct Answer
{
    int time;
    int cheezeCnt;
};

void findAir(bool checkMap[100][100])
{
    for(int i=0; i<H; i++){
        int j = 0;
        if(map[i][j] == 0 && checkMap[i][j] == false)
        {
            queue< pair<int, int> > q;
            q.push(make_pair(i, j));
            checkMap[i][j] = true;
            int dy[4] = {1, -1, 0, 0};
            int dx[4] = {0, 0, 1, -1};
            while(!q.empty())
            {
                int y = q.front().first; int x = q.front().second;
                q.pop();
                for(int k=0; k<4; k++){
                    int ty = y+dy[k]; int tx = x+dx[k];
                    if(ty < 0 || ty >= H || tx < 0 || tx >= W) continue;
                    if(map[ty][tx] == 1) continue;
                    if(checkMap[ty][tx] == true) continue;
                    q.push(make_pair(ty, tx));
                    checkMap[ty][tx] = true;
                }
            }
        }
    }
    for(int i=0; i<H; i++){
        int j = W-1;
        if(map[i][j] == 0 && checkMap[i][j] == false)
        {
            queue< pair<int, int> > q;
            q.push(make_pair(i, j));
            checkMap[i][j] = true;
            int dy[4] = {1, -1, 0, 0};
            int dx[4] = {0, 0, 1, -1};
            while(!q.empty())
            {
                int y = q.front().first; int x = q.front().second;
                q.pop();
                for(int k=0; k<4; k++){
                    int ty = y+dy[k]; int tx = x+dx[k];
                    if(ty < 0 || ty >= H || tx < 0 || tx >= W) continue;
                    if(map[ty][tx] == 1) continue;
                    if(checkMap[ty][tx] == true) continue;
                    q.push(make_pair(ty, tx));
                    checkMap[ty][tx] = true;
                }
            }
        }
    }

    for(int j=0; j<W; j++){
        int i = 0;
        if(map[i][j] == 0 && checkMap[i][j] == false)
        {
            queue< pair<int, int> > q;
            q.push(make_pair(i, j));
            checkMap[i][j] = true;
            int dy[4] = {1, -1, 0, 0};
            int dx[4] = {0, 0, 1, -1};
            while(!q.empty())
            {
                int y = q.front().first; int x = q.front().second;
                q.pop();
                for(int k=0; k<4; k++){
                    int ty = y+dy[k]; int tx = x+dx[k];
                    if(ty < 0 || ty >= H || tx < 0 || tx >= W) continue;
                    if(map[ty][tx] == 1) continue;
                    if(checkMap[ty][tx] == true) continue;
                    q.push(make_pair(ty, tx));
                    checkMap[ty][tx] = true;
                }
            }
        }
    }

    for(int j=0; j<W; j++){
        int i = H-1;
        if(map[i][j] == 0 && checkMap[i][j] == false)
        {
            queue< pair<int, int> > q;
            q.push(make_pair(i, j));
            checkMap[i][j] = true;
            int dy[4] = {1, -1, 0, 0};
            int dx[4] = {0, 0, 1, -1};
            while(!q.empty())
            {
                int y = q.front().first; int x = q.front().second;
                q.pop();
                for(int k=0; k<4; k++){
                    int ty = y+dy[k]; int tx = x+dx[k];
                    if(ty < 0 || ty >= H || tx < 0 || tx >= W) continue;
                    if(map[ty][tx] == 1) continue;
                    if(checkMap[ty][tx] == true) continue;
                    q.push(make_pair(ty, tx));
                    checkMap[ty][tx] = true;
                }
            }
        }
    }
}

int eraseCheese( bool checkMap[100][100])
{
    int dy[4] = {1, -1, 0, 0};
    int dx[4] = {0, 0, 1, -1};
    bool erase[100][100] = {false, };
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(map[i][j] == 0) continue;

            for(int k=0; k<4; k++){
                int y = i+dy[k]; int x = j+dx[k];
                if(y < 0 || y >= H || x < 0 || x >= W) continue;
                if(checkMap[y][x] == true){
                    erase[i][j] = true;
                    break;
                }
            }
        }
    }
    int cnt = 0;
    for(int i=0; i<H; i++)
    {
        for(int j=0; j<W; j++){
            if(erase[i][j] == true)
            { 
                map[i][j] = 0;
                cnt++;
            }
        }
    }
    return cnt;
};

bool mapCheck()
{
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(map[i][j] == 1) return false;
        }
    }
    return true;
};


Answer solve()
{
    Answer ans;
    if(mapCheck()){
        ans.time = 0;
        ans.cheezeCnt = 0;
        return ans;
    }
    for(int i=1; ; i++){
        bool checkMap[100][100] = {false};
        findAir(checkMap);

        ans.cheezeCnt = eraseCheese(checkMap);
        
        if(mapCheck()){
            ans.time = i;
            break;
        }
    }
    return ans;
};

int main()
{
    scanf("%d %d", &H, &W);
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            scanf("%d", &map[i][j]);
        }
    }

    Answer ans = solve();

    printf("%d\n", ans.time);
    printf("%d\n", ans.cheezeCnt);
}