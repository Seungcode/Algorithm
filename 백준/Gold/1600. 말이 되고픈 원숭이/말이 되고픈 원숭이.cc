#include <iostream>
#include <queue>

using namespace std;

struct monkey{
    int x;
    int y;
    int horse;
    int cnt;
};

int N, M, K;
int arr[201][201];
bool visited[201][201][31] = {false, };
int horse_x[8] = {1, 2, 1, 2, -1, -2, -1, -2};
int horse_y[8] = {-2, -1, 2, 1, -2, -1, 2, 1};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue<monkey> q;

void bfs(){
    q.push(monkey{0, 0, 0, 0});
    visited[0][0][0] = true;

    while(!q.empty()){
        monkey now = q.front();
        q.pop();

        if(now.x == N-1 && now.y == M-1) {
            cout<<now.cnt<<endl;
            return;
        }

        if(now.horse < K){
            for(int i = 0; i<8; i++){
                int nx = now.x + horse_x[i];
                int ny = now.y + horse_y[i];
                if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
                if(!visited[nx][ny][now.horse+1]&& arr[nx][ny] != 1){
                    visited[nx][ny][now.horse+1] = true;
                    q.push(monkey{nx, ny, now.horse+1, now.cnt+1});
                }
            }
        }

        for(int i = 0; i<4; i++){
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];
            if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
            if(!visited[nx][ny][now.horse] && arr[nx][ny] != 1){
                visited[nx][ny][now.horse] = true;
                q.push(monkey{nx, ny, now.horse, now.cnt+1});
            }
        }
    }
    cout<<-1;
}
int main() {
    cin>>K>>M>>N;

    for(int i = 0; i<N; i++) for(int j = 0; j<M; j++) cin>>arr[i][j];

    bfs();

    //bfs
}