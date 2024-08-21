#include <iostream>

using namespace std;

int N, M;
int parent[500001];

int find(int x){
    if(parent[x] == x) return x;
    else return find(parent[x]);
}

bool same_parent(int x, int y){
    return find(x) == find(y);
}

void make_union(int x, int y){
    x = find(x);
    y = find(y);
    if(x!=y) parent[y] = x;
}
int main() {
    cin >> N >> M;

    for(int i = 0; i<N; i++) parent[i] = i;

    for(int i = 0; i<M; i++){
        int a, b;
        cin>>a>>b;
        if(same_parent(a, b)){
            cout<<i+1;
            exit(0);
        }
        make_union(a, b);
    }

    cout<<0;

    return 0;
}