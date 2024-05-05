#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> arr(N);
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    vector<vector<int>> dp(N); // 각 원소를 마지막으로 하는 증가하는 부분 수열을 저장할 배열

    int max_length = 0; // 가장 긴 증가하는 부분 수열의 길이를 저장할 변수

    for(int i = 0; i < N; i++) {
        dp[i].push_back(arr[i]);
        for(int j = 0; j < i; j++) {
            if(arr[j] < arr[i] && dp[j].size() + 1 > dp[i].size()) {
                dp[i] = dp[j]; // 현재 원소를 추가한 부분 수열로 업데이트
                dp[i].push_back(arr[i]);
            }
        }
        max_length = max(max_length, (int)dp[i].size()); // 최대 길이 갱신
    }

    // 최대 길이를 가지는 부분 수열 찾기
    vector<int> lis;
    for(int i = 0; i < N; i++) {
        if(dp[i].size() == max_length) {
            lis = dp[i];
            break;
        }
    }

    // 결과 출력
    cout << max_length << '\n';
    for(int i : lis)
        cout << i << ' ';

    return 0;
}
