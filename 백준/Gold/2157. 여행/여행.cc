#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, K, answer = 0;
int arr[301][301] = {0, };
vector<pair<int, int>> ap[301];

struct node{
    int now;
    int cost;
    int cnt;

    bool operator<(const node &other) const {
        return cost > other.cost;
    }
};

void solution(){
    priority_queue<node> q;

    q.push({1, 0, 1});

    while(!q.empty()){
        node now = q.top();
        q.pop();

        if(now.now == N) {
            answer = max(answer, now.cost);
            continue;
        }

        if((arr[now.cnt][now.now] > now.cost || now.cnt == M) && now.now != 1) continue;

        for(auto i : ap[now.now]){
            int n_cost = now.cost + i.second;
            if(arr[now.cnt+1][i.first] >= n_cost) continue;
            arr[now.cnt+1][i.first] = n_cost;
            q.push({i.first, n_cost, now.cnt + 1});
        }
    }

    cout<<answer;
}

//입력받기
void input(){
    cin>>N>>M>>K;

    for(int i = 0; i < K; i++){
        int a, b, c;
        cin>>a>>b>>c;

        if(a > b) continue;

        ap[a].push_back({b, c});
    }

    solution();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();

    return 0;
}