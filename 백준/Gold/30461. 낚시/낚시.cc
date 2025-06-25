#include <iostream>
#include <algorithm>

using namespace std;

int N, M, Q;
int arr[2001][2001][2];

void input(){
    cin>>N>>M>>Q;

    for(int i = 1; i<=N; i++){
        for(int j = 1; j <= M; j++) cin>>arr[i][j][0];
    }
}

void solution() {
    input();

    for(int i = 1; i<=N; i++){
        for(int j = 1; j <= M; j++) {
            arr[i][j][0] += arr[i-1][j][0];
            arr[i][j][1] += arr[i][j][0] + arr[i-1][j-1][1];
        }
    }

    for(int i = 0; i < Q; i++){
        int a, b;
        cin>>a>>b;
        cout<<arr[a][b][1]<<"\n";
    }



}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solution();
}
