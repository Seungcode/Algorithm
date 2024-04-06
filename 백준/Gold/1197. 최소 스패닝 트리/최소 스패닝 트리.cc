#include <iostream>
#include<queue>

using namespace std;

struct comp{
    bool operator() (pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
        return a.second > b.second;
    }
};

//정점과 간선의 갯수
int N, M;
//가중치가 적인 간선부터 입력받기
priority_queue <pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, comp> arr;
//방문 여부 확인
int parent[10001] = {0, };
//가중치
long long int min_cost = 0;

int Find(int x){
    if(parent[x]==x)
        return x;
    else
        return parent[x] = Find(parent[x]);
}

bool same(int x, int y){
    int px = Find(x);
    int py = Find(y);
    return px==py;
}

void Union(int x, int y){
    x = Find(x);
    y = Find(y);
    if(x!=y) parent[y] = x;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력받기
    cin>>N>>M;

    for(int i = 1; i<=N; i++)
        parent[i] = i;

    for(int i = 0; i<M; i++){
        int a, b, c;
        cin>>a>>b>>c;
        arr.push({{a, b}, c});
    }

    //가중치 구하기
    while(!arr.empty()){
        if(same(arr.top().first.first, arr.top().first.second) == false){
            Union(arr.top().first.first, arr.top().first.second);
            min_cost += arr.top().second;
        }
        arr.pop();
    }

    //문제유형 : 최소 스패닝 (그래프 이론)
    cout<<min_cost;
}