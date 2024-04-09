#include <iostream>
#include <queue>

using namespace std;

//우선순위큐 비교용 구조체
struct comp{
    bool operator()(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
        return a.second > b.second;
    }
};

//변수 선언
int parent[100001] = {0, };
int N, K;
int answer = 0;
priority_queue <pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, comp> q;
vector<int> arr;

//부모 찾기
int find_p(int x){
    if(parent[x]==x)
        return x;
    return parent[x] = find_p(parent[x]);
}

//두 수 합치기
void union_two (int x, int y){
    x = find_p(x);
    y = find_p(y);
    if(x!=y) parent[y] = x;
}

//같은지 확인
bool same_parent(int x, int y){
    return find_p(x)==find_p(y);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력받기
    cin>>N>>K;

    for(int i = 0; i<K; i++){
        int a, b, c;
        cin>>a>>b>>c;
        //넣어줌과 동시에 정렬됨
        q.push({{a, b}, c});
    }

    //초기 셋팅
    for(int i = 1; i<=N; i++)
        parent[i] = i;

    //간선별 정리
    while(!q.empty()){
        if(!same_parent(q.top().first.first, q.top().first.second)){
            union_two(q.top().first.first, q.top().first.second);
            arr.push_back(q.top().second);
        }
        q.pop();
    }

    //가장 가중치가 높은 간선을 빼버림 -> 나머지는 이미 연결되어있음이 확인됨
    for(int i = 0; i<arr.size()-1; i++)
        answer += arr[i];

    cout<<answer;

    //문제유형 : 크루스칼 알고리즘 (최소 스패닝 트리)
}