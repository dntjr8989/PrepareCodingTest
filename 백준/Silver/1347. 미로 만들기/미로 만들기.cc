#include <stdio.h>

char map[50][50];
int N;
char note[50];
int dy[4]={1, 0, -1, 0};
int dx[4]={0, -1, 0, 1};
int dir = 0;
int py = 0;
int px = 0;
int mapy = 1;
int mapx = 1;

void solve()
{
    for(int k=0; k<N; k++){
        if(note[k] == 'R'){
            dir=(dir+1)%4;
        }
        else if(note[k] == 'L'){

            dir--;
            if(dir < 0) dir = 3;
        }
        else if(note[k] == 'F'){
            py = py+dy[dir]; px = px+dx[dir];

            if(py >= mapy)
            {
                mapy++;
                map[py][px] = '.';
            }
            else if(px >= mapx){
                mapx++;
                map[py][px] = '.';
            }
            else if(py < 0){
                for(int i=mapy-1; i>=0; i--){
                    for(int j=mapx-1; j>=0; j--){
                        map[i+1][j] = map[i][j];
                    }
                }
                for(int i=0; i<mapx; i++)
                {
                    map[0][i] = '#';
                }

                mapy++;
                py++;
                map[py][px] = '.';
            }
            else if(px < 0)
            {
                for(int i=mapy-1; i>=0; i--){
                    for(int j=mapx-1; j>=0; j--){
                        map[i][j+1] = map[i][j];
                    }
                }

                for(int i=0; i<mapy; i++)
                {
                    map[i][0] = '#';
                }

                mapx++;
                px++;
                map[py][px] = '.';
            }
            else{
                map[py][px] = '.';
            }
        }
    }
}

int main()
{
    scanf("%d", &N);
    scanf("%s", note);

    for(int i=0; i<50; i++){
        for(int j=0; j<50; j++) map[i][j] = '#';
    }

    map[mapy-1][mapx-1] = '.';
    solve();

    for(int i=0; i<mapy; i++){
        for(int j=0; j<mapx; j++){
            printf("%c", map[i][j]);
        }
        printf("\n");
    }    
}