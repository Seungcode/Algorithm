#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int N, M, H, answer = -1 * 1e9;
vector<pair<int, int>> arr[1001];
unordered_map<int, int> location;
unordered_map<int, int> house;

void input() {
    cin>>N;

    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            int a;
            cin>>a;
            if(a != 0) {
                arr[i].push_back({j, a});
            }
        }
    }

    cin>>M>>H;

    for(int i = 0; i<M; i++){
        int a, b;
        cin>>a>>b;
        location[a] = b;
    }

    for(int i = 0; i<H; i++){
        int a, b;
        cin>>a>>b;
        house[a] = b;
    }
}

void find(int a) {
    vector<int> cost(N + 1, 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    cost[a] = 0;
    pq.push({0, a});

    while (!pq.empty()) {
        auto [curCost, now] = pq.top();
        pq.pop();

        if (curCost > cost[now]) continue;

        for (auto [next, weight] : arr[now]) {
            int temp = curCost + weight;
            if (temp < cost[next]) {
                cost[next] = temp;
                pq.push({temp, next});
            }
        }
    }

    for (auto [loc, val] : location) {
        if (cost[loc] != 1e9) {
            int temp = val + house[a] - cost[loc];
            answer = max(answer, temp);
        }
    }
}


void solution() {
    input();

    for(auto i : house){
        find(i.first);
    }

    cout<<answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}
