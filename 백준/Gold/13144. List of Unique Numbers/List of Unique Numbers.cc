#include <iostream>
#include <unordered_map>

using namespace std;

int N;
int arr[100001] = {0, };

void input() {
    cin>>N;
    for(int i = 0; i<N; i++) cin>>arr[i];
}

void solution() {
    input();

    long long int answer = 0;

    int start = 0;
    int end = 0;
    unordered_map<int, int> cnt;
    cnt[arr[end]]++;

    while(start<=end && end < N){
        if(start == end) {
            end++;
            cnt[arr[end]]++;
        }
        if(cnt[arr[end]] == 2){
            while(arr[start] != arr[end]){
                answer += end - start;
                cnt[arr[start]]--;
                start++;
            }
            answer += end - start;
            cnt[arr[start]]--;
            start++;
        }
        end++;
        cnt[arr[end]]++;
    }

    while(start <= end){
        answer += end - start;
        start++;
    }

    cout<<answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}