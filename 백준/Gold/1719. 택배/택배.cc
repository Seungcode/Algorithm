#include <iostream>

using namespace std;

int N, M;
int arr[201][201];
int before[201][201];

void input() {
    cin>>N>>M;

    for(int i = 0; i<M; i++){
        int a, b, c;
        cin>>a>>b>>c;
        if(arr[a][b] > c){
            arr[a][b] = c;
            arr[b][a] = c;
            before[a][b] = b;
            before[b][a] = a;
        }
    }
}

void init() {
    for(auto &i : arr){
        for(auto &j : i) j = 1e9;
    }
}

void solution() {
    init();
    input();
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            for(int r = 1; r<=N; r++){
                if(arr[j][i] != 1e9 && arr[i][r] != 1e9){
                    if(arr[j][r] > arr[j][i] + arr[i][r]){
                        arr[j][r] = arr[j][i] + arr[i][r];
                        before[j][r] = before[j][i];
                    }
                }
            }
        }
    }


    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++) {
            if(i==j) cout<<"-"<<" ";
            else cout<<before[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}
