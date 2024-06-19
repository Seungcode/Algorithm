#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
int arr[301][301];
bool visited[301][301] = {false, };
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int i, int j){
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = true;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        int cnt = 0;
        for(int z = 0; z<4; z++){
            int nx = x + dx[z];
            int ny = y + dy[z];
            if(nx<0||ny<0||nx>=N||ny>=M) continue;
            if(!visited[nx][ny]) {
                if(arr[nx][ny] == 0)
                    cnt++;
                else {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        arr[x][y] = arr[x][y] - cnt;
        if(arr[x][y] < 0) arr[x][y] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;

    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++)
            cin>>arr[i][j];
    }

    int time = 0;

    int flag = 0;

    while(true){

        flag = 0;

        memset(visited, false, sizeof(visited));

        for(int i = 0; i<N; i++){
            for(int j = 0; j<M; j++) {
                if (arr[i][j] && !visited[i][j]) {
                    if(flag == 1){
                        cout<<time;
                        exit(0);
                    }
                    else {
                        flag = 1;
                        bfs(i, j);
                    }
                }
            }
        }

        if(flag == 0) break;

        time++;
    }

    cout<<0;
    //문제유형 : bfs
}
