#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int T, W, H, X, Y;
char arr[1001][1001];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
queue<pair<int, int>> q;

//위치를 저장할 구조체
struct node{
    int x;
    int y;
    int cnt;

    bool operator <(const node &other) const {
        return cnt > other.cnt;
    }
};

//불 번지기
void after_second(){
    queue<pair<int, int>> temp;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= H || ny >= W || nx < 0 || ny < 0) continue;
            if(arr[nx][ny] == '#' || arr[nx][ny] == '*') continue;
            arr[nx][ny] = '*';
            temp.push({nx, ny});
        }
    }

    q = temp;
}

//bfs
void solution(){
    priority_queue<node> po;
    po.push({X, Y, 0});

    after_second();

    int cnt = 0;

    while(!po.empty()){
        node now = po.top();
        po.pop();

        if(now.cnt != cnt){
            after_second();
            cnt ++;
        }

        for(int i = 0; i<4; i++){
            int x = now.x + dx[i];
            int y = now.y + dy[i];
            if(x >= H || y >= W || x < 0 || y < 0) {
                cout<<now.cnt+1<<endl;
                return;
            }
            if(arr[x][y] != '.') continue;
            //방문 한 곳 -> ,로 변경 / visited 배열 추가 사용 X
            arr[x][y] = ',';
            po.push({x, y, now.cnt + 1});
        }
    }

    cout<<"IMPOSSIBLE"<<endl;
}

//입력받기
void input(){
    cin>>T;

    for(int i = 0; i<T; i++){
        cin>>W>>H;
        for(int j = 0; j < H; j++){
            string a;
            cin>>a;
            for(int z = 0; z < W; z++){
                arr[j][z] = a[z];
                if(a[z] == '@'){
                    X = j;
                    Y = z;
                }
                else if(a[z] == '*') {
                    q.push({j, z});
                }
            }
        }

        solution();

        while(!q.empty()) q.pop();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();

    return 0;
}