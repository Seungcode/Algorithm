#include <iostream>

using namespace std;

int N;
int wheel[4][8];
int dir[4] = {0, };

void increseDir(int now, int direction){
    if(now == 3) return;
    if(wheel[now+1][(dir[now+1]+6)%8] != wheel[now][(dir[now]+2)%8]){
        increseDir(now+1, -1*direction);
        dir[now+1] -= direction;
        dir[now+1] = (dir[now+1] + 8) % 8;
    }
}

void decreseDir(int now, int direction){
    if(now == 0) return;
    if(wheel[now-1][(dir[now-1]+2)%8] != wheel[now][(dir[now]+6)%8]){
        decreseDir(now-1, -1*direction);
        dir[now-1] -= direction;
        dir[now-1] = (dir[now-1] + 8) % 8;
    }
}

void solution(){
    for(int i = 0; i<4; i++){
        string a;
        cin>>a;
        for(int j = 0; j<8; j++)  {
            wheel[i][j] = a[j] - '0';
        }
    }

    cin>>N;

    for(int i = 0; i<N; i++){
        int a, b;
        cin>>a>>b;
        a--;
        increseDir(a, -1*b);
        decreseDir(a, -1*b);
        dir[a] -= b;
        dir[a] = (dir[a] + 8) % 8;
    }
    int answer = 0;
    for(int i = 3; i>=0; i--){
        answer<<=1;
        if(wheel[i][dir[i]] == 1){
            answer += 1;
        }
    }
    cout<<answer;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}