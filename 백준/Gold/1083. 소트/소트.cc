#include <iostream>
#include <queue>

using namespace std;

int N, S;
int arr[51] = {0, };

void solution(){
    cin>>N;

    for(int i = 0; i<N; i++){
        cin>>arr[i];
    }

    cin>>S;

    int start = 0;
    while(start < N && S > 0){
        int idx = start;
        for(int i = start; i<=min(N-1, S + start); i++){
            if(arr[idx] < arr[i]) idx = i;
        }

        for(int i = idx; i > start; i--){
            swap(arr[i], arr[i-1]);
            S--;
        }

        start ++;
    }

    for(int i = 0; i<N; i++) cout<<arr[i]<<" ";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}