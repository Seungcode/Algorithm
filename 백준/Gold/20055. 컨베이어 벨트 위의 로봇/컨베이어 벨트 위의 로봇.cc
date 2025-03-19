#include <iostream>

using namespace std;

int N, K, cnt = 0;
int arr[201];
int remain[201];

void moveRail(){
    pair<int, int> now = {arr[2*N-1], remain[2*N-1]};
    for(int i = 2*N-2; i>=0; i--){
        arr[i+1] = arr[i];
        remain[i+1] = remain[i];
    }
    arr[N-1] = 0;
    arr[0] = now.first;
    remain[0] = now.second;
}

void moveRobot(){
    for(int i = N-1; i>0; i--){
        if(arr[i-1] == 1) {
            if (remain[i] > 0 && arr[i] == 0){
                remain[i]--;
                arr[i] = 1;
                arr[i-1] = 0;
                if(i == N-1) arr[i] = 0;
                if(remain[i] == 0) K--;
            }
        }
    }

    if(remain[0] > 0 && arr[0] == 0){
        remain[0] --;
        arr[0] = 1;
        if(remain[0] == 0) K--;
    }
}

void input(){
    cin>>N>>K;
    for(int i = 0; i<2*N; i++) cin>>remain[i];
}

void solution(){
    input();

    while(K>0){
        moveRail();
        moveRobot();
        cnt++;
    }
    cout<<cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}