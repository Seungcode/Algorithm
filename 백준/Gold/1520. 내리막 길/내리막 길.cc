#include <iostream>
#include <cstring>

using namespace std;

int N, M;
int arr[501][501];
int visited[501][501];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int dfs(int x, int y){
    if(x == N-1 && y == M-1) return 1;
    if(visited[x][y] != -1) return visited[x][y];

    visited[x][y] = 0;

    for(int i = 0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= N || ny >= M || nx<0 || ny<0) continue;
        else if(arr[nx][ny] >= arr[x][y]) continue;
        else visited[x][y] += dfs(nx, ny);
    }

    return visited[x][y];
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

    memset(visited, -1, sizeof(visited));

    cout<<dfs(0, 0)<<endl;

    //문제유형 : dfs
}
