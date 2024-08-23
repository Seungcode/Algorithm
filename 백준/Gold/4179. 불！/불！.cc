#include <iostream>
#include <queue>

using namespace std;

int N, M, X, Y;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char arr[1001][1001];
int fire_arr[1001][1001];
bool visited[1001][1001] = {false, };
queue<pair<int, int>> q;

struct maze{
    int x;
    int y;
    int cnt;
};

void bfs(){
    queue<maze> qu;
    qu.push({X, Y, 1});

    while(!qu.empty()){
        maze now = qu.front();
        qu.pop();

        for(int i = 0; i<4; i++){
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];
            if(nx>=N || ny >= M || nx < 0 || ny < 0) {
                cout<<now.cnt;
                exit(0);
            }
            if(arr[nx][ny] != '.' || (fire_arr[nx][ny] <= now.cnt + 1 && fire_arr[nx][ny] != 0) || visited[nx][ny]) continue;
            visited[nx][ny] = true;
            qu.push({nx, ny, now.cnt + 1});
        }
    }
}
void fire(){
    while(!q.empty()){
        int now_x = q.front().first;
        int now_y = q.front().second;
        q.pop();

        for(int i = 0; i<4; i++){
            int nx = now_x + dx[i];
            int ny = now_y + dy[i];
            if(nx>=N || ny >= M || nx < 0 || ny < 0 || visited[nx][ny] || arr[nx][ny] == '#') continue;
            visited[nx][ny] = true;
            fire_arr[nx][ny] = fire_arr[now_x][now_y] + 1;
            q.push({nx, ny});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N>>M;

    for(int i = 0; i<N; i++){
        string a;
        cin>>a;
        for(int j = 0; j<M; j++){
            arr[i][j] = a[j];
            if(arr[i][j] == 'F'){
                q.push({i, j});
                visited[i][j] = true;
                fire_arr[i][j] = 1;
            }
            else if(arr[i][j] == 'J'){
                X = i;
                Y = j;
            }
        }
    }

    fire();

    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++) visited[i][j] = false;
    }

    bfs();

    cout<<"IMPOSSIBLE";

}