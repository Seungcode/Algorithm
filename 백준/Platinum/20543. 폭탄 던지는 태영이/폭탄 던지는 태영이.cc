#include <iostream>

using namespace std;

int N, M;
long long arr[2001][2001] = {0, };
long long answer[2001][2001] = {0, };
long long sum[2001][2001] = {0, };

void input(){
    cin>>N>>M;

    for(int i = 1; i<=N; i++) {
        for(int j = 1; j <= N; j++) cin>>arr[i][j];
    }
}

void solution() {
    input();

    for(int i = 1; i<=N - M + 1; i++) {
        for(int j = 1; j <= N - M + 1; j++) {
            sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
            arr[i][j] += sum[i][j];

            sum[i][j] += arr[i][j] * -1;
            sum[i + M][j] += arr[i][j];
            sum[i][j + M] += arr[i][j];
            sum[i + M][j + M] += arr[i][j] * -1;

            answer[i + M/2][j + M/2] += arr[i][j] * -1;
        }
    }

    for(int i = 1; i<=N; i++) {
        for(int j = 1; j <= N; j++) cout<<answer[i][j]<<" ";
        cout<<"\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solution();
}
