#include <iostream>
#include <map>
using namespace std;

long long int N, P, Q;
map<long long int, long long int> arr;

void dp(long long int i){
    if(arr[i] != 0) return;
    if(arr[i/P] == 0) dp(i/P);
    if(arr[i/Q] == 0) dp(i/Q);
    arr[i] = arr[i/P] + arr[i/Q];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>P>>Q;

    arr[0] = 1;

    dp(N);

    cout<<arr[N];
    return 0;

    //문제유형 : hash+dp
}
