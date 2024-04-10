#include <iostream>
#include <queue>
#include <vector>

using namespace std;

//변수 선언
int N, M, K;
vector<int> relation[30001];
vector<pair<int, int>> friends;
bool visited[30001] = {false, };
int treats[30001] = {0, };
int dp[3001] = {0, };
int ans = 0;

//친구 그룹 만들기
void bfs(int u){
    queue <int> q;
    q.push(u);
    visited[u] = true;
    int cnt = 0;
    int candy = 0;
    while(!q.empty()){
        int now = q.front();
        candy += treats[now];
        cnt++;
        q.pop();
        for(auto i : relation[now]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
            }
        }
    }
    friends.push_back({cnt, candy});
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력받기
    cin>>N>>M>>K;

    for(int i=1; i<=N; i++)
        cin>>treats[i];

    for(int i = 0; i<M; i++){
        int a, b;
        cin>>a>>b;
        relation[a].push_back(b);
        relation[b].push_back(a);
    }

    //친구 그룹 만들기 -> 이미 묶인 사람은 굳이 한 번 더 할 이유가 없음
    for(int i = 1; i<=N; i++){
        if(!visited[i])
            bfs(i);
    }

    //값 구하기
    for(auto i : friends){
        //1부터로 하면 한 값을 여러 번 사용할 수도 있기 때문에 역순으로 진행
        for(int j = K-1; j>=0; j--){
            if(i.first > j)
                break;
            else
                dp[j] = max(dp[j], dp[j-i.first] + i.second);
            ans = max(ans, dp[j]);
        }
    }

    cout<<ans;

    //문제유형 : bfs + dp
}