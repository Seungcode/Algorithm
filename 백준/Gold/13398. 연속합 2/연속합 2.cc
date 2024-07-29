#include <iostream>

using namespace std;

int N, answer = 0;
int num[100001];
int arr[100001][2] = {0, };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;

    for(int i = 0; i<N; i++) cin>>num[i];

    answer = num[0];
    arr[0][0] = num[0];

    for(int i = 1; i<N; i++){
        arr[i][0] = max(arr[i-1][0] + num[i], num[i]);
        arr[i][1] = max(arr[i-1][1] + num[i], arr[i-1][0]);
        answer = max(arr[i][0], max(arr[i][1], answer));
    }

    cout<<answer;
}