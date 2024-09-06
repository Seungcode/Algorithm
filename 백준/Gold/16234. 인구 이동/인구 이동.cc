#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, L, R, sum = 0, cnt = 0;
int arr[51][51];
queue<pair<int, int>> q;
bool visited[51][51] = {false};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y, int b_cnt){

    for(int i = 0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

        if(abs(b_cnt - arr[nx][ny]) <= R && abs(b_cnt - arr[nx][ny]) >= L && !visited[nx][ny]){
            cnt++;
            visited[nx][ny] = true;
            q.push({nx, ny});
            sum += arr[nx][ny];
            dfs(nx, ny, arr[nx][ny]);
        }
    }
}

void initVisited(){
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++) visited[i][j] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N>>L>>R;

    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++) cin>>arr[i][j];
    }

    int time = 0;

    while(true){
        initVisited();
        cnt = 0;

        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++) {

                if(!visited[i][j]){
                    sum = arr[i][j];
                    visited[i][j] = true;

                    q.push({i, j});
                    
                    dfs(i, j, arr[i][j]);

                    int now = sum / q.size();

                    while(!q.empty()){
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        arr[x][y] = now;
                    }
                }
            }
        }
        if(cnt==0) break;

        time++;
    }

    cout<<time;

    return 0;
}