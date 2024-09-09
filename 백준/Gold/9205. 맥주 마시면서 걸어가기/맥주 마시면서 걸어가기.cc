#include <iostream>
#include <queue>

using namespace std;

int N, T, SX, SY, EX, EY;
int arr[101][2];
bool visited[101];

//방문 배열 초기화
void initArr(){
    for (bool & i : visited) i = false;
}

void solution(){
    initArr();

    queue<pair<int, int>> q;

    q.push({SX, SY});

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        //페스티벌에 갈 수 있다면
        if((abs(x - EX) + abs(y - EY)) <= 1000) {
            cout<<"happy"<<endl;
            return;
        }

        //다른 편의점에 갈 수 있다면
        for(int i = 0; i<N; i++){
            if(visited[i] || abs(x - arr[i][0]) + abs(y - arr[i][1]) > 1000) continue;

            visited[i] = true;
            q.push({arr[i][0], arr[i][1]});
        }
    }

    //페스티벌에 갈 수 없을 경우
    cout<<"sad"<<endl;
}

//압력받기
void input(){
    cin>>T;

    for(int i = 0; i<T; i++) {
        cin>>N;
        cin >> SX >> SY;
        for (int j = 0; j < N; j++) cin >> arr[j][0] >> arr[j][1];
        cin >> EX >> EY;

        solution();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();

    return 0;
}