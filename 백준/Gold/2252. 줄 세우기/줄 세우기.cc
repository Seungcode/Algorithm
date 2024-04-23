#include <map>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

//변수 선언
int N, M;
vector<vector<int>> arr;
map<int, int> degree;
queue <int> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력받기
    cin>>N>>M;
    arr.resize(N+1);

    for(int i = 0; i<M; i++){
        int x, y;
        cin>>x>>y;
        arr[x].push_back(y);
        degree[y]++;
    }

    
    //진입차수가 0일경우 넣어주기
    for(int i = 1; i<=N; i++)
        if(degree[i]==0) q.push(i);

    //위상정렬 -> 진입 차수가 0이 될 경우 출력
    for(int i = 1; i<=N; i++){
        if(q.empty()) break;
        int now = q.front();
        cout<<now<<" ";
        q.pop();
        //진입 차수 0인 것 기준으로 넣어주기
        for(auto a : arr[now]){
            if(--degree[a] == 0) {
                q.push(a);
            }
        }
    }

    //문제유형 : 위상정렬
}