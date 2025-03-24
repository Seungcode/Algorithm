#include <iostream>

using namespace std;

struct Shark{
    int x;
    int y;
    int speed;
    int dir;
    int size;
};

Shark arr[102][102] = {{0, 0, 0,0,0 }};

int R, C, M;

void input() {
    cin>>R>>C>>M;

    for(int i = 0; i<M; i++){
        int r, c, s, d, z;
        cin>>r>>c>>s>>d>>z;
        arr[r][c] = {r, c, s, d, z};
    }
}

Shark changeX(Shark current) {
    int cycle = (R - 1) * 2;
    int move = current.speed % cycle;

    for (int i = 0; i < move; i++) {
        if (current.dir == 1) current.x--;
        else current.x++;

        if(current.x <= 0 ){
            current.dir = 2;
            current.x = 2;
        }
        else if(current.x > R){
            current.dir = 1;
            current.x = R-1;
        }
    }
    return current;
}

Shark changeY(Shark current) {
    int cycle = (C - 1) * 2;
    int move = current.speed % cycle;

    for (int i = 0; i < move; i++) {
        if (current.dir == 4) current.y--;
        else current.y++;

        if(current.y <= 0 ){
            current.dir = 3;
            current.y = 2;
        }
        else if(current.y > C){
            current.dir = 4;
            current.y = C-1;
        }
    }
    return current;
}


void change(){
    Shark temp[102][102] = {};

    for(int i = 1; i<=R; i++){
        for(int j = 1; j <=C; j++){
            if(arr[i][j].size != 0){
                Shark current = arr[i][j];
                if(current.dir <= 2){
                    current = changeX(current);
                }
                else {
                    current = changeY(current);
                }
                if(temp[current.x][current.y].size < current.size){
                    temp[current.x][current.y] = current;
                }
            }
        }
    }

    for(int i = 1; i<=R; i++) {
        for (int j = 1; j <= C; j++) {
            arr[i][j] = temp[i][j];
        }
    }
}

void solution() {
    input();

    int answer = 0;
    int now = 1;

    while(now <= C){
        for(int i = 1; i <= R; i++){
            if(arr[i][now].size != 0){
                answer += arr[i][now].size;
                arr[i][now].size = 0;
                break;
            }
        }
        change();
        now++;
    }
    cout<<answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}
