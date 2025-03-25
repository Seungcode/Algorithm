#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Cctv{
    int x;
    int y;
    int type;

    bool operator<(Cctv const & other) const{
        return type < other.type;
    }
};

int N, M;
int arr[9][9];
int answer = 81;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
vector<Cctv> q;

void input() {
    cin>>N>>M;

    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++) {
            cin>>arr[i][j];
            if(arr[i][j] > 0 && arr[i][j] < 6){
                q.push_back({i, j, arr[i][j]});
            }
        }
    }

    sort(q.begin(), q.end());
}

void setFive(int set, Cctv now){
    for(int i = 0; i < 4; i++){
        int nx = now.x;
        int ny = now.y;
        while(true){
            nx += dx[i];
            ny += dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) break;
            if(arr[nx][ny] == 6) break;
            else if(arr[nx][ny] > 0) continue;
            arr[nx][ny] += set;
        }
    }
}

void setFour(int set, int dir, Cctv now){
    for(int i = 0; i < 4; i++){
        if(i == dir) continue;
        int nx = now.x;
        int ny = now.y;
        while(true){
            nx += dx[i];
            ny += dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) break;
            if(arr[nx][ny] == 6) break;
            else if(arr[nx][ny] > 0) continue;
            arr[nx][ny] += set;
        }
    }
}

void setThree(int set, int dir, Cctv now){
    for(int i = dir; i < dir + 2; i++){
        int nx = now.x;
        int ny = now.y;
        while(true){
            nx += dx[i%4];
            ny += dy[i%4];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) break;
            if(arr[nx][ny] == 6) break;
            else if(arr[nx][ny] > 0) continue;
            arr[nx][ny] += set;
        }
    }
}

void setTwo(int set, int dir, Cctv now){
    int nx = now.x;
    int ny = now.y;
    while(true){
        nx += dx[dir];
        ny += dy[dir];
        if(nx < 0 || ny < 0 || nx >= N || ny >= M) break;
        if(arr[nx][ny] == 6) break;
        else if(arr[nx][ny] > 0) continue;
        arr[nx][ny] += set;
    }

    nx = now.x;
    ny = now.y;
    while(true){
        nx += dx[dir+2];
        ny += dy[dir+2];
        if(nx < 0 || ny < 0 || nx >= N || ny >= M) break;
        if(arr[nx][ny] == 6) break;
        else if(arr[nx][ny] > 0) continue;
        arr[nx][ny] += set;
    }
}

void setFirst(int set, int dir, Cctv now){
    int nx = now.x;
    int ny = now.y;
    while(true){
        nx += dx[dir];
        ny += dy[dir];
        if(nx < 0 || ny < 0 || nx >= N || ny >= M) break;
        if(arr[nx][ny] == 6) break;
        else if(arr[nx][ny] > 0) continue;
        arr[nx][ny] += set;
    }
}

void count(){
    int temp = 0;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++) {
            if(arr[i][j] == 0) temp ++;
        }
    }
    answer = min(answer, temp);
}

void findRoute(int num){

    if(q[num].type == 5){
        setFive(-1, q[num]);
        if(num + 1 == q.size()) count();
        else findRoute(num+1);
        setFive(1, q[num]);
    }

    else if(q[num].type == 4){
        for(int i = 0; i<4; i++){
            setFour(-1, i, q[num]);
            if(num + 1 == q.size()) count();
            else findRoute(num+1);
            setFour(1, i, q[num]);
        }
    }

    else if(q[num].type == 3){
        for(int i = 0; i<4; i++){
            setThree(-1, i, q[num]);
            if(num + 1 == q.size()) count();
            else findRoute(num+1);
            setThree(1, i, q[num]);
        }
    }

    else if(q[num].type == 2){
        setTwo(-1, 0, q[num]);
        if(num + 1 == q.size()) count();
        else findRoute(num+1);
        setTwo(1, 0, q[num]);

        setTwo(-1, 1, q[num]);
        if(num + 1 == q.size()) count();
        else findRoute(num+1);
        setTwo(1, 1, q[num]);
    }

    else if(q[num].type == 1){
        for(int i = 0; i<4; i++){
            setFirst(-1, i, q[num]);
            if(num + 1 == q.size()) count();
            else findRoute(num+1);
            setFirst(1, i, q[num]);
        }
    }
}

void solution() {
    input();
    count();
    if(!q.empty())findRoute(0);
    cout<<answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}