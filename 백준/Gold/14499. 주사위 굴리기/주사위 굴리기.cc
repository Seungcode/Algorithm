#include <iostream>

using namespace std;

int N, M, X, Y, K;
int arr[20][20];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int dice[6] = {0, };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M>>X>>Y>>K;

    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++)
            cin>>arr[i][j];
    }

    for(int i = 0; i<K; i++){
        int dir;
        cin>>dir;
        X += dx[dir-1];
        Y += dy[dir-1];

        if(X<0 || Y<0 || X>=N || Y>=M){
            X -= dx[dir-1];
            Y -= dy[dir-1];
            continue;
        }

        int temp = dice[0];

        if(dx[dir-1] == 1){
            dice[0] = dice[5];
            dice[5] = dice[1];
            dice[1] = dice[4];
            dice[4] = temp;
        }

        else if(dx[dir-1] == -1){
            dice[0] = dice[4];
            dice[4] = dice[1];
            dice[1] = dice[5];
            dice[5] = temp;
        }

        else if(dy[dir-1] == 1){
            dice[0] = dice[3];
            dice[3] = dice[1];
            dice[1] = dice[2];
            dice[2] = temp;
        }

        else{
            dice[0] = dice[2];
            dice[2] = dice[1];
            dice[1] = dice[3];
            dice[3] = temp;
        }

        if(arr[X][Y] != 0){
            dice[1] = arr[X][Y];
            arr[X][Y] = 0;
        }
        else{
            arr[X][Y] = dice[1];
        }
        cout<<dice[0]<<"\n";
    }
    //문제유형 : 구현
}
