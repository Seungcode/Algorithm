#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
int arr[2001];
int visited[2001][2001] = {0};

int dp(int start, int end){

    if(visited[start][end] != 0) return  visited[start][end];

    if(start >= end) return 1;

    if(arr[start] != arr[end]) return -1;

    visited[start + 1][end - 1] = dp(start + 1, end - 1);

    if(visited[start +  1][end - 1] == 1) return 1;
    return 0;
}

void solution(){
    for(int i = 0; i<M; i++){
        int start, end;
        cin>>start>>end;

        if(dp(start, end) == 1) cout<<1<<"\n";
        else cout<<0<<"\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N;

    for(int i = 1; i<=N; i++) cin>>arr[i];

    cin>>M;

    solution();

    return 0;
}