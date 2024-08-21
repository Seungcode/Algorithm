#include <iostream>
#include <queue>

using namespace std;

int N, M;
vector<int> arr[32001];
int cnt[32001] = {0, };

void Solution(){
    priority_queue<int, vector<int>, greater<>> q;

    for(int i = 1; i<=N; i++){
        if(cnt[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int now = q.top();
        q.pop();

        cout<<now<<" ";

        for(auto i : arr[now]){
            cnt[i]--;
            if(cnt[i] == 0) q.push(i);
        }
    }
}

int main() {
    cin >> N >> M;

    for(int i = 0; i<M; i++){
        int a, b;
        cin>>a>>b;

        arr[a].push_back(b);
        cnt[b]++;
    }

    Solution();
    
    return 0;
}