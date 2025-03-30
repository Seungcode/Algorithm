#include <iostream>
#include <algorithm>

using namespace std;

int N;
long long int arr[2001];

void input() {
    cin>>N;
    for(int i = 0; i<N; i++) {
        cin>>arr[i];
    }
    sort(arr, arr+N);
}

void solution() {
    input();

    int answer = 0;

    for(int i = 0; i<N; i++){
        int start = i == 0 ? 1 : 0;
        int end = i == N-1 ? N-2 : N-1;
        while(start < end){
            if(start == i){
                start ++;
                continue;
            }
            if(end == i){
                end --;
                continue;
            }
            if(arr[start] + arr[end] == arr[i]){
                answer++;
                break;
            }
            else if(arr[start] + arr[end] > arr[i]){
                end--;
            }
            else {
                start++;
            }
        }
    }

    cout<<answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}