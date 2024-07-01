#include <iostream>
#include <queue>
#include <climits>

using namespace std;
long long 
int N, M, D, E;
int arr[100001] = {0, };
long long answer_up[100001];
long long answer_down[100001];
vector<pair<long long , long long>> arr_dis[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M>>D>>E;

    fill(answer_up, answer_up + N + 1, 2e14);

    fill(answer_down, answer_down + N + 1, 2e14);

    priority_queue<pair<long long , long long >, vector<pair<long long , long long >>, greater<>> q;

    for(int i = 1; i<=N; i++)
        cin>>arr[i];

    for(int i = 0; i<M; i++){
        int a, b, n;
        cin>>a>>b>>n;
        arr_dis[a].push_back({b, n});
        arr_dis[b].push_back({a, n});
    }

    q.push({ 0, 1});

    while(!q.empty()){
        long long  now = q.top().second;
        long long  cost = q.top().first;
        q.pop();

        if(answer_up[now] < cost*D) continue;

        for(auto i : arr_dis[now]){
            if(arr[now] >= arr[i.first]) continue;
            if(answer_up[i.first] > (cost + i.second)*D){
                answer_up[i.first] = (cost + i.second)*D;
                q.push({cost + i.second, i.first});
            }
        }
    }

    q.push({0, N});

    while(!q.empty()){
        long long now = q.top().second;
        long long cost = q.top().first;
        q.pop();

        if(answer_down[now] < cost*D) continue;

        for(auto i : arr_dis[now]){
            if(arr[now] >= arr[i.first]) continue;
            if(answer_down[i.first] > (cost + i.second)*D){
                answer_down[i.first] = (cost + i.second)*D;
                q.push({cost + i.second, i.first});
            }
        }
    }

    long long max_dis = -2e14;
    bool flag = false;

    for(int i = 1; i<=N; i++) {
        if (answer_up[i] != 2e14 && answer_down[i] != 2e14) {
            flag = true;
            max_dis = max(max_dis, arr[i]*E - (answer_up[i] + answer_down[i]));
        }
    }
    if(!flag) cout<<"Impossible";
    else cout<<max_dis;

    //문제유형 : 다익스트라
}
