#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node{
    int s;
    int e;
    int len;

    bool operator<(const Node & other) const{
        return len > other.len;
    }
};

int N, M, idx = 0;
int parent[6];
int arr[11][11];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool visited[11][11] = {false, };

vector<pair<int, int>> row[10];
vector<pair<int, int>> col[10];

priority_queue<Node> route;

int find(int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unionNode(int x, int y){
    x = find(x);
    y = find(y);

    if(x == y) return;
    if(x < y) parent[y] = x;
    else parent[x] = y;
}

void input(){
    cin>>N>>M;
    for(int i = 0; i<N; i++){
        for(int j = 0; j < M; j++) cin>>arr[i][j];
    }
}

void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});

    while(!q.empty()){
        pair<int, int> now = q.front();
        q.pop();

        row[now.first].push_back({now.second, idx});
        col[now.second].push_back({now.first, idx});

        for(int i = 0; i < 4; i++){
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(arr[nx][ny] == 0 || visited[nx][ny]) continue;
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

void makeRoute(){
    for(int i = 0; i<N; i++){
        for(int j = 0; j < row[i].size(); j++){
            for(int z = j + 1; z < row[i].size(); z++){
                if(row[i][j].second == row[i][z].second) continue;
                int temp = 0;
                for(int r = min(row[i][j].first, row[i][z].first) + 1; r < max(row[i][j].first, row[i][z].first); r++){
                    if(arr[i][r] != 0) break;
                    temp++;
                }
                if(temp < 2) continue;
                if(abs(row[i][j].first - row[i][z].first) - 1 == temp)
                    route.push({row[i][z].second, row[i][j].second, temp});
            }
        }
    }
    for(int i = 0; i<M; i++){
        for(int j = 0; j < col[i].size(); j++){
            for(int z = j + 1; z < col[i].size(); z++){
                if(col[i][j].second == col[i][z].second) continue;
                int temp = 0;
                for(int r = min(col[i][j].first, col[i][z].first) + 1; r < max(col[i][j].first, col[i][z].first); r++){
                    if(arr[r][i] != 0) break;
                    temp++;
                }
                if(temp < 2) continue;
                if(abs(col[i][j].first - col[i][z].first) - 1 == temp)
                    route.push({col[i][z].second, col[i][j].second, temp});
            }
        }
    }
}

void solution() {
    input();

    for(int i = 0; i<N; i++){
        for(int j = 0; j < M; j++) {
            if(arr[i][j] != 0 && !visited[i][j]){
                visited[i][j] = true;
                bfs(i, j);
                parent[idx] = idx;
                idx ++;
            }
        }
    }

    makeRoute();

    int answer = 0;

    while(!route.empty()){
        Node now = route.top();
        route.pop();

        if(find(now.s) == find(now.e))
            continue;

        unionNode(now.s, now.e);
        answer += now.len;
    }

    for(int i = 0; i<idx-1; i++){
        if(find(i) != find(i+1)){
            cout<<-1;
            return;
        }
    }

    cout<<answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}
