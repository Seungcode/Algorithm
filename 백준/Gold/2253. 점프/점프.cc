#include <iostream>
#include <cstring>

using namespace std;

int N, M;
int arr[10001][501];

int dp(int now, int jump){
    if(now == N) return 0;
    if(now > N ) return 10002;
    int &ret = arr[now][jump];
    if(ret != -1) return ret;

    ret = 10002;

    if(now+jump-1 <= N && arr[now+jump-1][0] != 0 && jump-1 > 0)
        ret = min(ret, dp(now+jump-1, jump-1)+1);
    if(now+jump <= N && arr[now+jump][0] != 0 && jump > 0)
        ret = min(dp(now+jump, jump)+1, ret);
    if(now+jump+1 <= N && arr[now+jump+1][0] != 0)
        ret = min(ret, dp(now+jump+1, jump+1)+1);

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;

    memset(arr, -1, sizeof(arr));

    for(int i = 0; i<M; i++){
        int a;
        cin>>a;
        arr[a][0] = 0;
    }

    int result = dp(1, 0);

    if(result == 10002) cout<<-1;
    else cout<<result;
    //문제유형 : dp
}
