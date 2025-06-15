#include <iostream>
#include <vector>

using namespace std;

int N, K, X;
int arr[200001] = {0, };
int sum[200001] = {0, };

void input(){
    cin>>N>>K>>X;

    for(int i = 1; i<=N; i++){
        cin>>arr[i];
        sum[i] = arr[i] + sum[i-1];
    }
}

void solution() {
    input();

    int start = 1;
    int end = 1;
    int answer = 0;

    while(end <= N){
        if(start > end) {
            end ++;
            continue;
        }

        int money = (sum[start - 1] * X) + sum[N] - sum[end];

        if(money >= K) {
            answer = max(answer, end - start + 1);
            end ++;
        }
        else start ++;
    }

    if(answer == 0) answer = -1;
    cout<<answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solution();
}
