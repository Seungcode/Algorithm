#include <iostream>
#include <queue>
#include <limits.h>

using namespace std;

int N;
int arr[125][125] = {0, };
int visited[125][125];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(){
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = arr[0][0];
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || ny<0 || nx>=N || ny>=N) continue;
            if(visited[nx][ny] > visited[x][y] + arr[nx][ny]){
                visited[nx][ny] = visited[x][y] + arr[nx][ny];
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cnt = 1;
    while(true){
        cin>>N;
        if(N==0) break;
        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++) {
                cin >> arr[i][j];
                visited[i][j] = INT_MAX;
            }
        }
        dfs();
        cout<<"Problem "<<cnt<<": "<<visited[N-1][N-1]<<"\n";
        cnt++;
    }

    //문제유형 : 다익스트라
}
