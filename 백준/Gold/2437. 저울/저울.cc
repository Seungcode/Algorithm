#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[1001];

void input(){
    cin>>N;

    for(int i = 0; i < N; i++){
        cin>>arr[i];
    }

    sort(arr, arr + N);
}

void solution() {
    input();

    int answer = 1;

    for (int i = 0; i < N; i++) {
        if (arr[i] > answer) {
            break;
        }
        answer += arr[i];
    }

    cout<<answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solution();
}
