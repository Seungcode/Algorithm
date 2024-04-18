#include <iostream>
#include <map>
#include <queue>

using namespace std;

//변수 설정
int N, M;
char arr[1001][1001] ;
int visited[1001][1001] = {0, };
int idx = 0;
int answer = 0;
map <char, pair<int, int>> go;

void bfs(int x, int y){
    //초기 선언
    queue <pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = idx;
    
    while(!q.empty()){
        int n_x = q.front().first;
        int n_y = q.front().second;
        q.pop();
        
        //아직 방문을 안 한 경우
        if(visited[n_x + go[arr[n_x][n_y]].first][n_y + go[arr[n_x][n_y]].second] == 0){
            visited[n_x + go[arr[n_x][n_y]].first][n_y + go[arr[n_x][n_y]].second] = idx;
            q.push({n_x + go[arr[n_x][n_y]].first, n_y + go[arr[n_x][n_y]].second});
        }
        
        //현재 방문 경로에서 사이클이 생겼을 경우
        else if(visited[n_x + go[arr[n_x][n_y]].first][n_y + go[arr[n_x][n_y]].second] == idx) answer++;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력받기
    cin>>N>>M;

    //방향 입력
    go['D'] = {1, 0};
    go['L'] = {0, -1};
    go['U'] = {-1, 0};
    go['R'] = {0, 1};

    //입력받기
    for(int i = 0; i<N; i++){
        string a;
        cin>>a;
        for(int j = 0; j<M; j++)
            arr[i][j] = a[j];
    }

    //아직 가지 않은 구간이 있으면 탐색 시작
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if(visited[i][j] == 0){
                idx++;
                bfs(i, j);
            }
        }
    }

    //출력
    cout<<answer;

    //문제유형 : bfs
}