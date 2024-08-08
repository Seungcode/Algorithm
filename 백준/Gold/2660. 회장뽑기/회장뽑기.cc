#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[51][51] = {0, };
int answer[51] = {0, };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;

    for(int i = 1; i<=N; i++) {
        for (int j = 1; j <= N; j++) arr[i][j] = 10e7;
        arr[i][i] = 0;
    }

    while(true){
        int a, b;
        cin>>a>>b;

        if(a==-1 && b==-1) break;

        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            for(int z = 1; z<=N; z++){
                if(arr[j][i] != 10e7 && arr[i][z] != 10e7) arr[j][z] = min(arr[j][z], arr[j][i] + arr[i][z]);
            }
        }
    }

    int result = 10e7;

    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++) answer[i] = max(answer[i], arr[i][j]);
        result = min(result, answer[i]);
    }

    queue<int> q;

    for(int i = 1; i<=N; i++){
        if(answer[i] == result) q.push(i);
    }

    cout<<result<<" "<<q.size()<<"\n";

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}