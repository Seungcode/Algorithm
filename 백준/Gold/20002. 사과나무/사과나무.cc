#include <iostream>

using namespace std;

int N;
int arr[301][301] = {0, };
int answer = -1000 * 300 * 300;

void input() {
    cin >> N;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++) cin>>arr[i][j];
    }
}

void makeSum(){
    for(int i = 1; i<=N; i++){
        for(int j = 1; j <= N; j++) {
            arr[i][j] += arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
            for(int z = 1; z <= min(i, j); z++){
                answer = max(answer, arr[i][j] - arr[i-z][j] - arr[i][j-z] + arr[i-z][j-z]);
            }
        }
    }
}

void solution() {
    input();
    makeSum();
    cout<<answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solution();
}
