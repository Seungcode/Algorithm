#include <vector>
#include <iostream>
#include <limits.h>

using namespace std;

int N;
string b;
int cnt = INT_MAX;


void solve(int flag, string a){
    int answer = 0;

    //시작 경우의 수 나누기
    if(flag == 0){
        answer++;
        a[0] = a[0] == '0' ? '1' :'0';
        a[1] = a[1] == '0' ? '1' :'0';
    }

    //O(N^2) 이 아닌 O(N)내에 문제를 해결하기 위함
    for(int i = 1; i<N; i++){
        if(a[i-1]!=b[i-1]){
            answer++;
            a[i-1] = a[i-1] == '0' ? '1' :'0';
            a[i] = a[i] == '0' ? '1' :'0';
            if(i < N-1)
                a[i+1] = a[i+1] == '0' ? '1' :'0';
        }
    }

    if(a==b) cnt = min(answer, cnt);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;
    string a;
    cin>>a>>b;

    solve(0, a);
    solve(1, a);

    if(cnt == INT_MAX) cout<<-1;
    else cout<<cnt;

    //문제유형 : 그리디

    return 0;
}
