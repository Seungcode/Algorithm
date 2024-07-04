#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> arr[51];
bool visited[51];
int start, answer = 0;

void dfs(int now){
    if(now == M) return;
    if(arr[now].empty() || (arr[now].size() == 1 && arr[now][0] == M)){
        answer++;
        return;
    }

    for(auto i : arr[now]){
        if(!visited[i]) {
            visited[i] = true;
            dfs(i);
            visited[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;

    for(int i = 0; i<N; i++){
        int a;
        cin>>a;
        if(a==-1)
            start = i;
        else
            arr[a].push_back(i);
    }

    cin>>M;

    dfs(start);

    cout<<answer;

    //문제유형 : dfs
}
