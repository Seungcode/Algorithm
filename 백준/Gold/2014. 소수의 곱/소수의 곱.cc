#include <iostream>
#include <queue>
#include <map>

using namespace std;

int N, K;
long long arr[101];
long long max_num;
map<long long, int> visited;
priority_queue<long long, vector<long long>, greater<>> q;

int main() {
    cin>>N>>K;
    for(int i = 0; i<N; i++){
        cin>>arr[i];
        q.push(arr[i]);
        visited[arr[i]] ++;
    }

    max_num = arr[N-1];

    int cnt = 1;

    while(cnt != K){
        long long now = q.top();
        q.pop();
        for(int i = 0; i<N; i++) {
            if (arr[i] > now ||(q.size()>K && max_num <= arr[i]*now)) break;
            if(visited[arr[i]*now] == 0){
                visited[arr[i]*now] ++;
                q.push(now * arr[i]);
                max_num = max(max_num, now*arr[i]);
            }
        }
        cnt++;
    }

    cout<<q.top();
}
