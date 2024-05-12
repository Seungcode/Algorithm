#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M, K;
char arr[31][31][31];
bool visited[31][31][31] = {false, };
pair<int, pair<int, int>> start;
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

void bfs(){
    queue<pair<pair<int, pair<int, int>>, int>> q;
    q.push({start, 0});

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second.first;
        int z = q.front().first.second.second;
        int cnt = q.front().second;
        q.pop();
        for(int i = 0; i<6; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            if(nx<0 || ny<0 || nz<0 || nx>=N || ny>=M || nz>=K) continue;
            if(arr[nx][ny][nz] == 'E'){
                cout<<"Escaped in "<<cnt+1<<" minute(s)."<<endl;
                return;
            }
            if(!visited[nx][ny][nz] && arr[nx][ny][nz] == '.'){
                visited[nx][ny][nz] = true;
                q.push({{nx, {ny, nz}}, cnt+1});
            }
        }
    }
    cout<<"Trapped!"<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true){
        cin>>N>>M>>K;
        if(N==0 && M==0 && K==0) break;

        for(int i = 0; i<N; i++){
            for(int j = 0; j<M; j++){
                string a;
                cin>>a;
                for(int z = 0; z<K; z++) {
                    arr[i][j][z] = a[z];
                    if(arr[i][j][z] == 'S') start = {i, {j, z}};
                }
            }
        }

        bfs();

        memset(visited, false, sizeof(visited));
    }

    return 0;

    //문제유형 : bfs
}
