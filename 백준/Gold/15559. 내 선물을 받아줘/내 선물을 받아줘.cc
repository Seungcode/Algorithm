#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int N, M, idx = 0, answer = 0;

int visit[1001][1001] = {0, };
string arr[1001];
vector<int> parent;

int find(int a){
    if(parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}

void unionNode(int a, int b){
    a = find(a);
    b = find(b);

    if(a<b){
        parent[b] = a;
    }
    else parent[a] = b;
}

void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});

    while(!q.empty()){
        pair<int, int> now = q.front();
        q.pop();

        int nx = now.first;
        int ny = now.second;

        if(arr[nx][ny] == 'N') nx--;
        else if(arr[nx][ny] == 'S') nx++;
        else if(arr[nx][ny] == 'W') ny--;
        else ny++;

        if(visit[nx][ny] == idx) continue;
        if(visit[nx][ny] == 0) {
            visit[nx][ny] = idx;
            q.push({nx, ny});
        }
        else if(find(idx) != find(visit[nx][ny])){
            answer--;
            unionNode(idx, visit[nx][ny]);
        }
    }
}

void input() {
    cin>>N>>M;

    for(int i = 0; i<N; i++){
        cin>>arr[i];
    }
}

void solution() {
    parent.push_back(idx);
    input();

    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if(visit[i][j] == 0){
                answer++;
                idx++;
                parent.push_back(idx);
                visit[i][j] = idx;
                bfs(i, j);
            }
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
