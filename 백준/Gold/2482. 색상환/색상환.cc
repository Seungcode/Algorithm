#include <iostream>

using namespace std;

int N, K;
long long int arr[1001][1001] = {0, };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>K;

    //초기 값 세팅 -> 하나의 색만을 고를 경우
    for(int i = 0; i<=N; i++) {
        arr[i][0] = 1;
        arr[i][1] = i;
    }

    //점점 키워가면서 확인하기 -> 이거보다 작은 경우 만들 수 있는 합 + 이 경우 만들 수 있는 합
    for(int i = 2; i<=K; i++){
        for(int j = 2; j<=N; j++)
            arr[j][i] = (arr[j-2][i-1] + arr[j-1][i])%1000000003;
    }

    //[N][K]일 경우에는 처음 칸을 쓰지 못 함 -> N-1개로 만들 수 있는 합(N번 사용 X) + N번을 사용하는 경우
    cout<<(arr[N-1][K] + arr[N-3][K-1])%1000000003;

    return 0;

    //문제유형 : dp
}
