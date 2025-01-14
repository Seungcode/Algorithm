#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[1001]= {0, };
int score[1001] = {0, };

void solution(){
    int mx, my;

    for(int i = 1; i<=N; i++){
        int mx = score[i];
        int my = score[i];
        for(int j = i; j>0; j--){
            mx = max(mx, score[j]);
            my = min(my, score[j]);
            arr[i] = max(arr[i], arr[j-1] + (mx - my));
        }
    }

    cout<<arr[N];
}

//입력받기
void input(){
    cin>>N;

    for(int i = 1; i<=N; i++) cin>>score[i];

    solution();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();

    return 0;
}