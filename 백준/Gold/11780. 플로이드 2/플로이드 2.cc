#include <iostream>
#include <vector>

using namespace std;

int N, M;
pair<int, vector<int>> arr[101][101];

void init() {
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            arr[i][j].first = 0;
        }
    }
}

void input(){
    cin>>N>>M;
    init();
    for(int i = 0; i<M; i++){
        int a, b, c;
        cin>>a>>b>>c;
        if(arr[a][b].first == 0 || arr[a][b].first > c) {
            arr[a][b].first = c;
            arr[a][b].second = {a, b};
        }
    }
}

void solution() {
    input();

    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            for(int r = 1; r<=N; r++){
                if(j==r) continue;
                if(arr[j][i].first != 0 && arr[i][r].first != 0){
                    int cost = arr[j][i].first + arr[i][r].first;
                    if(arr[j][r].first == 0 || arr[j][r].first > cost){
                        arr[j][r].first = cost;
                        arr[j][r].second.clear();
                        for(auto x : arr[j][i].second) arr[j][r].second.push_back(x);
                        for(int x = 1; x < arr[i][r].second.size(); x++) arr[j][r].second.push_back(arr[i][r].second[x]);
                    }
                }
            }
        }
    }

    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            cout<<arr[i][j].first<<" ";
        }
        cout<<"\n";
    }

    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            cout<<arr[i][j].second.size()<<" ";
            for(auto r : arr[i][j].second) cout<<r<<" ";
            cout<<"\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}