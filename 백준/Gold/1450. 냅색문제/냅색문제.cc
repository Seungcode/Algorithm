#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
int arr[31] = {0, };
vector<long long> A_subsets, B_subsets;

void generateSubsets(int start, int end, vector<long long>& subsets, long long sum, bool flag) {
    if(start > end || sum > K) return;
    if(flag) subsets.push_back(sum);
    generateSubsets(start+1, end, subsets, sum+arr[start], true);
    generateSubsets(start+1, end, subsets, sum, false);
}

void solution() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> arr[i];

    int mid = N / 2;
    //부분집합의 합 생성(dfs)
    generateSubsets(0, mid, A_subsets, 0, false);
    generateSubsets(mid, N, B_subsets, 0, false);

    sort(A_subsets.begin(), A_subsets.end());

    long long answer = 1;
    //A의 부분집합 만으로 만들 수 있는 경우
    answer += upper_bound(A_subsets.begin(), A_subsets.end(), K) - A_subsets.begin();
    //B의 부분집합 만으로 만들 수 있는 경우
    answer += upper_bound(B_subsets.begin(), B_subsets.end(), K) - B_subsets.begin();
    
    //A와 B의 부분집합을 모두 써야만 만들 수 있는 경우
    for (long long b : B_subsets) {
        answer += upper_bound(A_subsets.begin(), A_subsets.end(), K - b) - A_subsets.begin();
    }

    cout << answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}
