#include <iostream>

using namespace std;

int N, M;
int arr[1000001] = {0, };
int sum[1000001] = {0, };

void input(){
    cin>>N>>M;

    for(int i = 1; i <= N; i++) cin>>arr[i];
    for(int i = 0; i < M; i++){
        int A, B, C;
        cin>>A>>B>>C;
        sum[A] += C;
        sum[B + 1] -= C;
    }
}

void solution() {
    input();

    for (int i = 1; i <= N; i++) {
        sum[i] += sum[i-1];

        cout<<arr[i] + sum[i]<<" ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solution();
}
