#include <algorithm>
#include <iostream>
using namespace std;

long long int arr[1000001] = {0, };
int N;

void initArr() {
    arr[1] = 1;
    arr[2] = 2;
}

void solution() {
    initArr();

    for (int i = 3; i <= N; i++) {
        if (i%2 != 0) {
            arr[i] = arr[i-1];
        }
        else {
            arr[i] = (arr[i-1] + arr[i/2])%1000000000;
        }
    }

    cout<<arr[N];
}

void input() {
    cin>>N;

    solution();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();

    return 0;
}