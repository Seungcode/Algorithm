#include <iostream>
#include <vector>
using namespace std;

int N;
bool visited[101] = {false, };
vector<int> arr[101];
vector<int> result;

void dfs(int now){
    for(auto i : arr[now]){
        if(visited[i])
            result.push_back(i);
        else {
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

    for(int i = 1; i<=N; i++){
        int a;
        cin>>a;
        arr[a].push_back(i);
    }
    for(int i = 1; i<=N; i++){
        visited[i] = true;
        dfs(i);
        visited[i] = false;
    }
    
    cout<<result.size()<<endl;

    for(auto i : result)
        cout<<i<<'\n';
    return 0;

    //문제유형 : dfs
}
