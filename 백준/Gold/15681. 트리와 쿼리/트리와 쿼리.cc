#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, R, Q;
bool visited[100001] = {false, };
int sizes[100001] = {0, };
vector<int> arr[100001];

void dfs(int now){
    int temp = 1;
    for(auto i : arr[now]){
        if(!visited[i]){
            visited[i] = true;
            dfs(i);
            temp += sizes[i];
        }
    }
    sizes[now] = temp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>R>>Q;

    for(int i = 1; i < N; i++) {
        int a, b;
        cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    visited[R] = true;
    dfs(R);

    for(int i = 1; i <= Q; i++) {
        int a;
        cin>>a;
        cout<<sizes[a]<<'\n';
    }

    return 0;

    //문제유형 : dfs
}
