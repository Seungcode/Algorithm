#include <iostream>
#include <string>
#include <limits.h>
#include <vector>
#include <queue>

using namespace std;

int N, M, K;
vector<pair<int, unsigned long long>> arr[100001];
unsigned long long dist[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M>>K;

    for(int i = 0; i<=N; i++)
        dist[i] = 1e18;

    priority_queue<pair<unsigned long long, int>, vector<pair<unsigned long long, int>>, greater<>> temp;

    for(int i = 0; i<M; i++){
        int start, end, len;
        cin>>start>>end>>len;

        arr[end].push_back({start, len});
    }

    for(int i = 0; i<K; i++) {
        int start;
        cin>>start;
        temp.push({0, start});
        dist[start] = 0;
    }

    while(!temp.empty()){
        int now = temp.top().second;
        unsigned long long value = temp.top().first;

        temp.pop();

        if(dist[now] < value) continue;

        for(auto i : arr[now]){
            int n_now = i.first;
            unsigned long long n_cost = i.second;

            if(dist[n_now] > value + n_cost){
                temp.push({value + n_cost, n_now});
                dist[n_now] = value + n_cost;
            }
        }
    }

    int max_idx;
    unsigned long long max_cost = 0;

    for(int i = 1; i<=N; i++){
        if(max_cost < dist[i]){
            max_idx = i;
            max_cost = dist[i];
        }
    }

    cout<<max_idx<<endl<<max_cost;

    //문제유형 : 다익스트라
}
