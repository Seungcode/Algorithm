#include <iostream>
#include <queue>

using namespace std;

//언니와 동생의 위치를 담을 배열
int N, K;
bool arr[100001] = {false, };

//현재 언니 위치에서 동생 위치를 가기 위한 최소 시간을 구하기 -> bfs(너비우선탐색) 사용
void bfs(){
    //우선순위 사용 -> 순간이동을 우선 처리 함
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<>> now;

    now.push({0, N});
    arr[N] = true;

    while(!now.empty()){
        int now_sis = now.top().second;
        int cnt = now.top().first;
        now.pop();
        //만일 원하는 위치까지 왔을 경우 -> 바로 리턴
        if(now_sis==K){
            cout<<cnt;
            return;
        }
        if(2*now_sis < 100001 && !arr[2*now_sis]){
            arr[2 * now_sis] = true;
            now.push({cnt, 2 * now_sis});
        }
        if(now_sis-1>=0 && !arr[now_sis-1]){
            arr[now_sis-1] = true;
            now.push({cnt+1, now_sis - 1});
        }
        if(!arr[now_sis+1] && now_sis+1 < 100001){
            arr[now_sis+1] = true;
            now.push({cnt+1, now_sis+1});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>K;

    bfs();

    //문제유형 : bfs

    return 0;
}