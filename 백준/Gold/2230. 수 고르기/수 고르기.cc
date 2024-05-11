#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int N, K;
int first, second;
long long int tem = INT_MAX;
long long int arr[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>K;

    //초기 값 세팅 -> 하나의 색만을 고를 경우
    for(int i = 0; i<N; i++)
        cin>>arr[i];

    sort(arr, arr+N);

    first = 0;
    second = 1;

    while(first<=second && second<N){
        if(arr[second] - arr[first] >= K){
            tem = min(tem, arr[second] - arr[first]);
            first++;
        }
        else
            second++;
    }

    cout<<tem;

    return 0;

    //문제유형 : two-pointer
}
