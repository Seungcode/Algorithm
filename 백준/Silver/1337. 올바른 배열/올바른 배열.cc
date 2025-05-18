#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[50];

void input(){
    cin>>N;

    for(int i = 0; i < N; i++){
        cin>>arr[i];
    }
    sort(arr, arr + N);
}

void solution() {
    input();

    int answer = 4;
    int temp;

    for(int i = 0; i < N; i++){
        temp = 4;
        for(int j = 1; j < 5; j++){
            if(i + j >= N) break;
            if(arr[i] + 4 >= arr[i + j]) temp --;
        }
        answer = min(answer, temp);
    }

    cout<<answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solution();
}
