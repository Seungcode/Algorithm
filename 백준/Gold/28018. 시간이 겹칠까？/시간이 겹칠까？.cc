#include <iostream>

using namespace std;

int N, M;
int arr[1000001] = {0, };

void input(){
    cin>>N;

    for(int i = 0; i<N; i++){
        int s, e;
        cin>>s>>e;

        arr[s] ++;
        arr[e+1] --;
    }

    cin>>M;
}

void solution() {
    input();

    for(int i = 1; i<=1000000; i++){
        arr[i] += arr[i-1];
    }

    for(int i = 0; i<M; i++){
        int a;
        cin>>a;
        cout<<arr[a]<<"\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solution();
}
