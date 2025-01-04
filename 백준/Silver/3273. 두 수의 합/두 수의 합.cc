#include <iostream>
#include <algorithm>

using namespace std;

int N, X;
int arr[100001] = {0, };
int answer = 0;


void solution(){
    int start = 0;
    int end = N-1;

    sort(arr, arr+N);

    while(start < end){
        if(arr[start] + arr[end] == X) {
            answer++;
            start++;
        }
        else if(arr[start] + arr[end] < X){
            start++;
        }
        else{
            end--;
        }
    }

    cout<<answer;
}

//입력받기
void input(){
    cin>>N;

    for(int i = 0; i<N; i++) cin>>arr[i];

    cin>>X;

    solution();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();

    return 0;
}