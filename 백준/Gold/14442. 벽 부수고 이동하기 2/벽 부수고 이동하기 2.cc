#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M, K;
string arr[1001];
int cost[11][1001][1001];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

struct Node{
    int x;
    int y;
    int cnt;
    int crash;
};

void init() {
    memset(cost, 1000*1000 + 1, sizeof(cost));
}

void input(){
    cin>>N>>M>>K;

    for(int i = 0; i<N; i++) {
        cin>>arr[i];
    }
}

void solution() {
    init();
    input();

    queue<Node> q;
    q.push({0, 0, 1, 0});
    cost[0][0][0] = 1;

    while(!q.empty()){
        Node now = q.front();
        q.pop();

        if(cost[now.crash][now.x][now.y] < now.cnt) continue;
        
        if(now.x == N-1 && now.y == M-1) {
            cout<<now.cnt;
            return;
        }

        for(int i = 0; i<4; i++){
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];
            int temp = now.cnt + 1;

            
            if(nx<0 || ny<0 || nx >= N || ny >= M) continue;

            if(arr[nx][ny] == '1'){
                if(now.crash + 1 <= K){
                    if(cost[now.crash + 1][nx][ny] <= temp) continue;
                    q.push({nx, ny, temp, now.crash + 1});
                    cost[now.crash + 1][nx][ny] = temp;
                }
            }

            else{
                if(cost[now.crash][nx][ny] <= temp) continue;
                q.push({nx, ny, temp, now.crash});
                cost[now.crash][nx][ny] = temp;
            }
        }
    }

    cout<<-1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}