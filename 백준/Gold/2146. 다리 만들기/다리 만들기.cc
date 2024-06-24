#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N;
int arr[101][101];
bool visited[101][101] = {false, };
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1,-1};

int cnt = 1;
int answer = 10001;

void find_island(int i, int j){
    queue<pair<int, int>> q;

    q.push({i, j});

    arr[i][j] = cnt;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for(int z = 0; z<4; z++){
            int nx = x + dx[z];
            int ny = y + dy[z];

            if(nx<0||ny<0||ny>=N||nx>=N) continue;
            if(!visited[nx][ny] && arr[nx][ny] == 1){
                visited[nx][ny] = true;
                arr[nx][ny] = cnt;
                q.push({nx, ny});
            }
        }
    }
}

int find_bridge(int i, int j, int now){
    queue<pair<pair<int, int>, int>> q;

    q.push({{i, j}, 0});

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int len = q.front().second;

        q.pop();

        for(int z = 0; z<4; z++){
            int nx = x + dx[z];
            int ny = y + dy[z];

            if(nx<0||ny<0||ny>=N||nx>=N) continue;
            if(arr[nx][ny] != now && arr[nx][ny] != 0) {
                return len;
            }
            if(!visited[nx][ny] && arr[nx][ny] == 0){
                visited[nx][ny] = true;
                q.push({{nx, ny}, len+1});
            }
        }
    }

    return 10001;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;

    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++)
            cin>>arr[i][j];
    }

    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++) {
            if(arr[i][j] == 1 && !visited[i][j]) {
                find_island(i, j);
                cnt++;
            }
        }
    }

    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++) {
            if(arr[i][j] != 0) {
                memset(visited, false, sizeof(visited));
                answer = min(answer, find_bridge(i, j, arr[i][j]));
            }
        }
    }

    cout<<answer;

    //문제유형 : bfs
}
