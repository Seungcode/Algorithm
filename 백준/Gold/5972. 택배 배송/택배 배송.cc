#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<pair<int, int>> arr[50001];
int cost[50001] = {0, };

void init(){
    for(int i = 2; i<=N; i++) cost[i] = 50000*1000 + 1;
}

void input(){
    cin>>N>>M;

    for(int i = 0; i<M; i++) {
        int a, b, c;
        cin>>a>>b>>c;
        arr[a].push_back({b, c});
        arr[b].push_back({a, c});
    }
}

void solution() {
    input();
    init();

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    q.push({0, 1});

    while(!q.empty()){
        pair<int, int> now = q.top();
        q.pop();

        if(cost[now.second] < now.first) continue;

        for(auto i : arr[now.second]){
            int temp = now.first + i.second;
            if(cost[i.first] <= temp) continue;
            cost[i.first] = temp;
            q.push({temp, i.first});
        }
    }

    cout<<cost[N];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}
