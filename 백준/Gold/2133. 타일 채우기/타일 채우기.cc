#include <iostream>

using namespace std;

int N;
int arr[31] = {0, };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    arr[0] = 1;
    arr[1] = 0;
    arr[2] = 3;

    for(int i = 3; i<=N; i++){
        if(i%2!=0) arr[i] = 0;
        else arr[i] = arr[i-2]*4 - arr[i-4];
    }

    cout<<arr[N];

    //문제유형 : dp
}
