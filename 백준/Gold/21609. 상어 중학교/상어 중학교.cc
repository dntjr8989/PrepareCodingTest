#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int N, M; // N : 한변 크기, M : 색상 개수
int blockMap[20][20];

void input()
{
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &blockMap[i][j]);
        }
    }
};

void paste(vector< pair<int, int> > a, vector< pair<int, int> > b)
{
    while(a.size() > 0){
        a.pop_back();
    }

    for(int i=0; i<b.size(); i++)
    {
        a.push_back(b[i]);
    }
};

vector < pair<int, int> > findGroup()
{
    bool check[20][20] = {false,};
    int dy[4] = {0, 0, 1, -1};
    int dx[4] = {1, -1, 0, 0};

    int max = -1; int maxRainbow = -1;
    vector< pair<int, int> > maxGroup;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(check[i][j] == true || blockMap[i][j] <= 0) continue;

            queue< pair<int, int > > q;
            vector < pair<int, int > > t;
            
            q.push(make_pair(i, j)); check[i][j] = true;
            bool rainbowCheck[20][20] = {false};
            int color = blockMap[i][j];
            int rainBow = 0;
            while(!q.empty()){
                int y = q.front().first; int x = q.front().second;
                t.push_back(q.front());
                q.pop();

                for(int k=0; k<4; k++){
                    int ty = y+dy[k]; int tx = x+dx[k];
                    if(ty < 0 || ty >= N || tx < 0 || tx >= N) continue;
                    if(blockMap[ty][tx] <= -1) continue;
                    if(blockMap[ty][tx] != 0 && blockMap[ty][tx] != color) continue;
                    if(check[ty][tx] == true) continue;
                    if(blockMap[ty][tx] == 0 && rainbowCheck[ty][tx] == true) continue;

                    if(blockMap[ty][tx] == 0) { rainBow++; rainbowCheck[ty][tx] = true;}
                    else {  check[ty][tx] = true; }
                    q.push(make_pair(ty,tx));
                }
            }
            if((int)t.size() > max)
            {
                max = t.size(); maxGroup = t; maxRainbow = rainBow;
            }
            else if((int)t.size() == max){
                if(rainBow >= maxRainbow)
                {
                    max = t.size(); maxGroup = t; maxRainbow = rainBow;
                }
            }
        }
    }
    return maxGroup;
};

void gravity()
{
    for(int i=0; i<N; i++){
        int blank = 0;
        for(int j=N-1; j>=0; j--)
        {
            if(blockMap[j][i] == -3){
                blank++;
            }
            else if(blockMap[j][i] == -1) blank=0;
            else{
                if(blank > 0)
                {
                    blockMap[j+blank][i] = blockMap[j][i];
                    blockMap[j][i] = -3;
                }
            }
        }
    }
}

void rotate()
{
    int newBlockMap[20][20];

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            newBlockMap[i][j] = blockMap[j][N-1-i];
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            blockMap[i][j] = newBlockMap[i][j];
        }
    }
};

int solve()
{
    int score = 0;
    while(1){
    
        //크기가 가장 큰 블록 그룹 찾기
        vector< pair<int, int> > blockGroup = findGroup();
        if(blockGroup.size() <= 1) break;
        //그룹 제거
        for(int i=0; i<blockGroup.size(); i++){
            blockMap[blockGroup[i].first][blockGroup[i].second] = -3;
        }
        score = score + blockGroup.size() * blockGroup.size();

        //중력 작용
        gravity();

        //90도 반시계 회전
        rotate();

        //중력 작용
        gravity();

    }
    return score;
}

int main()
{
    input();
    printf("%d\n", solve());

    return 0;
}