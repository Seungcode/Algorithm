#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//배열크기를 받아 줄 변수와 배열, 좌표 이동 값, 최종 인원 수를 담을 변수 선언
int N, M;
vector<vector<string>> arr;
bool visited[601][601] = {false, };
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int cnt = 0;

void bfs(int i, int j){
    queue<pair<int, int>> now;
    
    //시작위치
    visited[i][j] = false;
    now.push({i, j});
    
    while(!now.empty()){
        int now_x = now.front().first;
        int now_y = now.front().second;
        now.pop();
        //사람일 경우
        if(arr[now_x][now_y] == "P")
            cnt++;
        //다음 칸 찾기
        for(int z = 0; z<4; z++){
            int tx = now_x + dx[z];
            int ty = now_y + dy[z];
            if(tx>=N || tx<0 || ty>=M || ty<0)
                continue;
            if(!visited[tx][ty] && arr[tx][ty] != "X"){
                visited[tx][ty] = true;
                now.push({tx, ty});
            }
        }
    }
    
    //사람을 만나지 못하는 경우
    if(cnt==0){
        cout<<"TT";
        return;
    }
    cout<<cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    //현재 위치를 저장할 변수 선언
    int x, y;

    cin>>N>>M;
    arr.resize(N, vector<string>(M));

    //위치를 배열에 할당함과 동시에 시작 위치 저장
    for(int i = 0; i<N; i++){
        string a;
        cin>>a;
        for(int j = 0; j<M; j++){
            arr[i][j] = a[j];
            if(a[j]=='I'){
                x = i;
                y = j;
            }
        }
    }

    //bfs 실행 (현재 위치부터!)
    bfs(x, y);
    
    //문제 유형 : bfs, dfs (너비 우선, 깊이 우선 뭘 쓰든 큰 상관 없을 듯!)

}
