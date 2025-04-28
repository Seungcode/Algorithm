#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

int N;
vector<pair<int, int>> arr;
vector<pair<int, int>> q;
unordered_map<int, long long> cnt;
map<pair<int, int>, long long> ans;

void input() {
    cin>>N;

    for(int i = 0; i < N; i++){
        int a, b;
        cin>>a>>b;
        arr.push_back({b, a});
        q.push_back({b, a});
    }

    sort(q.begin(), q.end(), greater<>());
}

void solution() {
    input();

    long long sum = 0;
    queue<pair<int, int>> tem_q;

    while(!q.empty()){
        pair<int, int> now = q.back();
        q.pop_back();

        ans[now] = sum - cnt[now.second];
        tem_q.push(now);

        long long temp = now.first;

        while(!q.empty()){
            if(now.first != q.back().first) break;

            now = q.back();
            q.pop_back();

            ans[now] = sum - cnt[now.second];
            tem_q.push(now);
            temp += now.first;
        }

        sum += temp;
        while(!tem_q.empty()){
            pair<int, int> current = tem_q.front();
            tem_q.pop();

            cnt[current.second] += current.first;
        }
    }


    for(auto i : arr){
        cout<<ans[i]<<"\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}
