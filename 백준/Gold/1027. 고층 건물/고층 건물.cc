#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[51] = {0, };
int cnt[51] = {0, };
int answer = 0;

bool check(int A, int B){
    double diff = (double)(arr[B] - arr[A]) / (double)(B-A);

    for(int i = 1; i<B - A; i++){
        if(diff*i + arr[A] <= arr[A + i]) {
            return false;
        }
    }

    return true;
}

void solution(){
    for(int i = 0; i<N; i++){
        for(int j = i+1; j < N; j++) {
            if(check(i, j)){
                cnt[i]++;
                cnt[j]++;
            }
        }
        answer = max(answer, cnt[i]);
    }

    cout<<answer;
}

//입력받기
void input(){
    cin>>N;

    for(int i = 0; i<N; i++) cin>>arr[i];

    solution();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();

    return 0;
}