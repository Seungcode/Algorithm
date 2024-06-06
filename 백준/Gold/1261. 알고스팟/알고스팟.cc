#include <iostream>
#include <queue>
#include <limits.h>
#include <cstring>

using namespace std;

int N, M;
int arr[101][101] = {0, };
int visited[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs() {
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = 0;

    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
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

    cin >> M >> N;

    memset(visited, 10001, sizeof(visited));

    for (int i = 0; i < N; i++) {
        string a;
        cin>>a;
        for (int j = 0; j < M; j++)
            arr[i][j] = a[j] - '0';
    }

    bfs();

    cout << visited[N-1][M-1];

    return 0;
    
    //문제유형 : 다익스트라
}
