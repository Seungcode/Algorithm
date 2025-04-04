#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
vector<int> parent;
vector<pair<int, int>> swan;
queue<pair<int, int>> water;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int arr[1501][1501];
int idx = 1;

int findParent(int x){
    if(parent[x] == x) return x;
    return parent[x] = findParent(parent[x]);
}

void unionUnit(int x, int y){
    x = findParent(x);
    y = findParent(y);
    if(x != y){
        if (x < y) parent[y] = x;
        else parent[x] = y;
    }
}


void input() {
    cin>>N>>M;

    for(int i = 0; i<N; i++){
        string a;
        cin>>a;

        for(int j = 0; j<M; j++){
            if(a[j] == 'X') arr[i][j] = -1;
            else if(a[j] == '.') {
                arr[i][j] = 0;
                water.push({i, j});
            }
            else {
                swan.push_back({i, j});
                arr[i][j] = 0;
                water.push({i, j});
            }
        }
    }
}

void makeUnit(int x, int y) {
    queue<pair<int, int>> q;
    arr[x][y] = idx;
    q.push({x, y});

    while(!q.empty()){
        pair<int, int> now = q.front();
        q.pop();

        for(int i = 0; i<4; i++){
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];

            if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
            if(arr[nx][ny] != 0) continue;
            arr[nx][ny] = idx;
            q.push({nx, ny});
        }
    }
}

void extendWater(){
    queue<pair<int, int>> ice;

    while(!water.empty()){
        int x = water.front().first;
        int y = water.front().second;
        water.pop();

        for(int i = 0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
            if(arr[nx][ny] == -1){
                arr[nx][ny]=arr[x][y];
                ice.push({nx, ny});
            }
        }
    }

    while(!ice.empty()){
        int x = ice.front().first;
        int y = ice.front().second;
        water.push({x, y});
        ice.pop();

        for(int i = 0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
            if(arr[nx][ny] != -1 && arr[nx][ny] != arr[x][y]){
                unionUnit(arr[nx][ny], arr[x][y]);
            }
        }
    }
}

void solution() {
    input();

    parent.push_back(0);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(arr[i][j] == 0){
                parent.push_back(idx);
                makeUnit(i, j);
                idx++;
            }
        }
    }

    int time = 0;
    while(true){
        if(findParent(arr[swan[0].first][swan[0].second])
        == findParent(arr[swan[1].first][swan[1].second])) break;

        extendWater();
        time++;
    }

    cout<<time;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}