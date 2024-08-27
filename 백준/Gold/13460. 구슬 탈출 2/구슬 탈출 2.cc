#include <iostream>
#include <queue>

using namespace std;

int N, M, RX, RY, BX, BY;
char arr[11][11];
bool visited[11][11][2] = {false, };
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

struct ball{
    int rx;
    int ry;
    int bx;
    int by;
    int cnt;
};

void bfs(){
    queue<ball> q;
    q.push({RX, RY, BX, BY, 0});

    while(!q.empty()){
        ball now = q.front();
        q.pop();
        
        if(now.cnt == 10) continue;

        for(int i = 0; i<4; i++){
            int nrx = now.rx;
            int nry = now.ry;

            int nbx = now.bx;
            int nby = now.by ;

            int temp_r = 0, temp_b = 0;
            bool flag_r = false, flag_b = false;

            while(true){
                if(arr[nrx + dx[i]][nry + dy[i]] == '#') break;

                nrx += dx[i];
                nry += dy[i];

                if(arr[nrx][nry] == 'O') flag_r = true;

                temp_r++;
            }

            while(true){
                if(arr[nbx + dx[i]][nby + dy[i]] == '#') break;

                nbx += dx[i];
                nby += dy[i];

                if(arr[nbx][nby] == 'O') flag_b = true;

                temp_b ++;
            }

            if(nbx == nrx && nby == nry){
                if(temp_b < temp_r){
                    nrx -= dx[i];
                    nry -= dy[i];
                }
                else{
                    nbx -= dx[i];
                    nby -= dy[i];
                }
            }

            if(flag_b) continue;

            if(flag_r){
                cout<<now.cnt+1;
                exit(0);
            }


            visited[nrx][nry][0] = true;
            visited[nbx][nby][1] = true;

            q.push({nrx, nry, nbx, nby, now.cnt +  1});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N>>M;

    for(int i = 0; i<N; i++){
        string a;
        cin>>a;
        for(int j = 0; j<M; j++) {
            arr[i][j] = a[j];

            if(arr[i][j] == 'R'){
                RX = i;
                RY = j;

                visited[i][j][0] = true;
            }

            else if(arr[i][j] == 'B'){
                BX = i;
                BY = j;

                visited[i][j][1] = true;
            }
        }
    }

    bfs();

    cout<<-1;
    return 0;
}