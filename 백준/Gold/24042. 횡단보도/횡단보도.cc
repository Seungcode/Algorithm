#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int N, M;
vector<pair<int, int>> arr[100001];

void input(){
    cin>>N>>M;

    for(int i = 0; i<M; i++){
        int a, b;
        cin>>a>>b;
        arr[a].push_back({b, i});
        arr[b].push_back({a, i});
    }
}
void solution() {
    input();

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> q;
    q.push({0, 1});

    long long visited[100001];
    for(int i = 0; i<=N; i++){
        visited[i] = LONG_LONG_MAX;
    }

    visited[1] = 0;

    while(!q.empty()){
        pair<long long, int> now = q.top();
        q.pop();

        if(visited[now.second] < now.first) continue;

        for(auto i : arr[now.second]){
            long long cost = (now.first/M)*M + i.second >= now.first ? (now.first/M)*M + i.second : ((now.first/M) + 1)*M + i.second;
            cost ++;
            if(cost >= visited[i.first]) continue;
            visited[i.first] = cost;
            q.push({cost, i.first});
        }
    }

    cout<<visited[N];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}