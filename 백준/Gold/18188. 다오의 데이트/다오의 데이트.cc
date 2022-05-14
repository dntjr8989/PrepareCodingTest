#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Position{
    int y;
    int x;
    int move;
    vector<char> record;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);   

    int H, W;
    char map[20][20];
    int checkmap[20][20];
    int moveN;
    char selectMove[20][2];
    Position Dao, Disiny;
    char move[4] = {'W', 'A', 'S', 'D'};
    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, -1, 0, 1};

    cin >> H >> W;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> map[i][j];
            if(map[i][j] == 'D') {Dao.y = i; Dao.x = j; Dao.move = 0;}
            checkmap[i][j] = -1;
        }
    }
    cin >> moveN;
    for(int i=0; i<moveN; i++){
        cin >> selectMove[i][0] >> selectMove[i][1];
    }
    queue<Position> q;
    q.push(Dao);
    while(q.size() > 0){
        Position t = q.front();
        
        if(map[t.y][t.x] == 'Z'){
            cout << "YES" << endl;
            for(int i=0; i<t.record.size(); i++){
                cout << t.record[i];
            }
            return 0;
        }
        else if(t.move > moveN){
            cout << "NO" << endl;
            return 0;
        }
        q.pop();
        for(int i=0; i<4; i++){
            bool flag = false;
            for(int j=0; j<2; j++){
                if(move[i] == selectMove[t.move][j]){flag = true; break;}
            }
            if(flag == true){
                if(t.y+dy[i] >= 0 && t.y+dy[i] < H && t.x+dx[i] >= 0 && t.x+dx[i] < W){
                    
                    if(map[t.y+dy[i]][t.x+dx[i]] != '@'){
                        Position newt;
                        newt.y = t.y+dy[i]; newt.x = t.x+dx[i]; 
                        newt.move = t.move+1; newt.record = t.record; newt.record.push_back(move[i]); 
                        q.push(newt);
                    }
                }
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}