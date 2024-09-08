#include <iostream>
using namespace std;

int N, M, cnt = 0;
int X, Y, D;
int arr[51][51];
int px[4] = {-1, 0, 1, 0};
int py[4] = {0, 1, 0, -1};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

//압력받기
void input(){
    cin>>N>>M;
    cin>>X>>Y>>D;

    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++) cin>>arr[i][j];
    }
}

void solution(){
    while(true){
        //멈추는 조건
        if(X<0 || Y<0 || X>=N || Y>=M ||arr[X][Y] == 1) break;

        //청소 안 한 방일 떄
        if(arr[X][Y] == 0) {
            cnt++;
            arr[X][Y] = -1;
        }

        bool flag = false;

        //다른 방향의 방 확인
        for(int i = 0; i<4; i++){
            int nx = X + dx[i];
            int ny = Y + dy[i];

            if(nx<0 || ny<0 || nx>=N || ny>=M ) continue;

            //청소 안 한 방이 있다먄
            if(arr[nx][ny] == 0) {
                flag = true;
                break;
            }

        }

        //청소 안 한 방이 없다면 -> 후진
        if(!flag){
            X -= px[D];
            Y -= py[D];
        }
        //청소 안 한 방이 있다면 -> 돌려가면서 올바른 방향으로 전진
        else{
            while(true){
                D = (D+3)%4;

                if(arr[X+px[D]][Y+py[D]] == 0){
                    X = X + px[D];
                    Y = Y + py[D];
                    break;
                }
            }
        }
    }

    //출력
    cout<<cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    solution();

    return 0;
}