#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<long long int, long long int>> arr;
long long int sum[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;

    for(int i = 0; i<N; i++){
        long long int a, b;
        cin>>a>>b;
        arr.push_back({a, b});
    }

    sort(arr.begin(), arr.end());

    sum[0] = arr[0].second;

    for(int i = 1; i<N; i++)
        sum[i] = arr[i].second + sum[i-1];

    long long int start = 0, end = N-1;
    long long int idx = 1e9;

    while(start <= end){
        long long int mid = (start + end) / 2;
        if(sum[mid] >= sum[N-1] - sum[mid]){
            end = mid - 1;
            idx = min(idx, arr[mid].first);
        }
        else start = mid + 1;
    }

    cout<<idx;

    //문제유형 : 이분탐색
}
