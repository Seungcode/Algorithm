#include <iostream>
#include <map>
#include <vector>

using namespace std;

int N, M, K;
string arr[11];
map<string, int> answer;
vector<string> res;

int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[8] = { 0, 0, 1, -1, -1, 1, -1, 1};

void dfs(string a, int x, int y){
    if(a.length() >= 6) return;
    if(answer[a] != 0) answer[a] ++;
    for(int i = 0; i<8; i++){
        int nx = (x + dx[i] + N)%N;
        int ny = (y + dy[i] + M)%M;
        dfs(a+arr[nx][ny] , nx, ny );
    }
}

int main() {
    cin>>N>>M>>K;

    for(int i = 0; i<N; i++) cin>>arr[i];
    for(int i = 0; i<K; i++){
        string a;
        cin>>a;
        res.push_back(a);
        answer[a] = 1;
    }

    string temp = "";

    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++) dfs(temp + arr[i][j], i, j);
    }

    for(auto i : res) cout<<answer[i] - 1<<"\n";
}