#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
long long int answer = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    int arr[10001];
    int arr_sum[10001];

    for(int i = 0; i<N; i++)
        cin>>arr[i];

    sort(arr, arr+N);

    for(int i = 1; i<N; i++)
        arr_sum[i-1] = arr[i] - arr[i-1];

    sort(arr_sum, arr_sum+N-1, greater());

    for(int i = M-1; i<N; i++)
        answer += arr_sum[i];

    cout<<answer;

    return 0;

    //문제유형 : greedy
}
