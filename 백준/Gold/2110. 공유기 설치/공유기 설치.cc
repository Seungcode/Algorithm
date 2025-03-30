#include <iostream>
#include <algorithm>

using namespace std;

int N, C;
int arr[200001];

void input() {
    cin>>N>>C;
    for(int i = 0; i<N; i++) {
        cin>>arr[i];
    }
    sort(arr, arr+N);
}

void solution() {
    input();

    int answer = 0;
    int start = 1;
    int end = arr[N-1] - arr[0];

    while(start <= end){
        //0번째 칸에는 항상 설치하고 시작
        int router = 1;
        int middle = (start + end) / 2;
        int st = arr[0];

        //이 거리로 설치할 수 있는 라우터의 수
        for(int i = 1; i<N; i++){
            if(arr[i] - st >= middle){
                router++;
                st = arr[i];
            }
        }

        //해당 거리로 가능하다면 더 긴 거리로 가능한지 탐색
        if(router >= C){
            answer = max(answer, middle);
            start = middle + 1;
        }
        //해당 거리로 불가능하다면 더 짧은 거리로 가능한지 탐색
        else end = middle - 1;
    }

    cout<<answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}