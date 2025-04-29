#include <iostream>
#include <unordered_map>

using namespace std;

int N, K;
int arr[200001] = {0, };
unordered_map<long long, long long> cnt;

void input() {
    cin>>N>>K;
}

void solution() {
    input();

    long long answer = 0;

    for(int i = 1; i <= N; i++){
        cin>>arr[i];
        arr[i] += arr[i-1];
        if(arr[i] == K) answer++;
        answer += cnt[arr[i] - K];
        cnt[arr[i]]++;
    }

    cout<<answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}
