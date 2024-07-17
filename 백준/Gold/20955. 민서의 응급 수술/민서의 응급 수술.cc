#include <iostream>

using namespace std;

int N, M, answer = 0;
int parent[100001];

int find(int x){
    if(parent[x] == x) return x;
    return find(parent[x]);
}

void make_union(int x, int y){
    x = find(x);
    y = find(y);
    if(x!=y) {
        if(y>x)parent[y] = x;
        else parent[x] = y;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;

    for(int i = 1; i<=N; i++) parent[i] = i;

    for(int i = 0; i<M; i++){
        int u, v;
        cin>>u>>v;
        if(find(u) == find(v)) answer++;
        else make_union(u, v);
    }

    for(int i = 2; i<=N; i++){
        if(find(1) != find(i)){
            answer++;
            make_union(1, i);
        }
    }

    cout<<answer;
}