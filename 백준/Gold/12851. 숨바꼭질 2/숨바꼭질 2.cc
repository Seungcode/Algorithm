#include <iostream>
#include <limits.h>
#include <queue>

using namespace std;

//변수 선언
int N, K;
bool point[100001] = {false, };
int answer = 0;
int min_cnt = INT_MAX;
int dx[3] = {1, -1, 0};
queue<pair<int, int>> q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //각자 위치 입력받기
    cin>>N>>K;

    //처음 위치 넣어주기
    q.push({N, 0});

    //bfs사용하여 계산하기
    while(!q.empty()){
        int now = q.front().first;
        int cnt = q.front().second;
        if(cnt > min_cnt)
            break;
        point[now] = true;
        if(now == K){
            min_cnt = cnt;
            answer ++;
        }
        q.pop();
        for(int i = 0; i<3; i++){
            int tx = now + dx[i];
            if(dx[i] == 0)
                tx += now;
            if(tx<0 || tx > 100001 )
                continue;
            if(!point[tx]){
                q.push({tx, cnt+1});
            }
        }
    }

    cout<<min_cnt<<endl;
    cout<<answer;
    //문제유형 : bfs
}