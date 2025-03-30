#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int N;
long long int arr[2001];
unordered_map<long long int, int> cnt;

void input() {
    cin>>N;
    for(int i = 0; i<N; i++) {
        cin>>arr[i];
        cnt[arr[i]] ++;
    }
    sort(arr, arr+N);
}

void solution() {
    input();

    int answer = 0;

    for(int i = 0; i<N; i++){
        for(int j = i+1; j<N; j++){
            if(arr[i] + arr[j] > arr[N-1]) break;
            if(arr[i] + arr[j] < arr[0]) continue;
            if(arr[i] == arr[i] + arr[j] || arr[j] == arr[i] + arr[j]){
                if(arr[i] == arr[j] && cnt[arr[i]] == 2){
                    continue;
                }
                if(cnt[arr[i] + arr[j]] == 1){
                    continue;
                }
            }
            answer += cnt[arr[i] + arr[j]];
            cnt[arr[i] + arr[j]] = 0;
        }
    }

    cout<<answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}