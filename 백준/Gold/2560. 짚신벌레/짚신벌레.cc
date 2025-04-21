#include <iostream>

using namespace std;

int a, b, d, N;
long long arr[1000001] = {0, };
long long cnt[1000001] = {0, };

void input() {
    cin>>a>>b>>d>>N;
}

void solution() {
    input();

    arr[0] = 1;

    cnt[a] = 1;
    cnt[b] = -1;
    arr[d] = -1;

    for(int i = 1; i<=N; i++){
        cnt[i] += cnt[i-1] + 1000;
        cnt[i] %= 1000;

        arr[i] += (cnt[i] + arr[i-1] + 1000);
        arr[i] %= 1000;

        if(i + a <= N) {
            cnt[i+a] += cnt[i];
            cnt[i+a] %= 1000;
        }

        if(i + b <= N) {
            cnt[i+b] -= cnt[i]%1000;
            cnt[i+b] %= 1000;
        }

        if(i + d <= N) {
            arr[i+d] -= cnt[i] + 1000;
            arr[i+d] %= 1000;
        }
    }
    cout<<arr[N];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}
