#include <iostream>
#include <limits.h>

using namespace std;

int N;
char arr[5][5];
int min_an = INT_MAX;
int max_an = INT_MIN;

void dfs(int i, int j, int now, char op){
    if(i>=N || j>=N) return;
    if(arr[i][j]-'0'>=0 && arr[i][j]-'0'<=9){
        if(op=='+')
            now += (arr[i][j] - '0');
        else if(op=='-')
            now -= (arr[i][j] - '0');
        else if(op=='*')
            now *= (arr[i][j] - '0');
    }
    else
        op = arr[i][j];
    if(i==N-1 && j==N-1){
        min_an = min(now, min_an);
        max_an = max(now, max_an);
        return;
    }
    dfs(i+1, j, now, op);
    dfs(i, j+1, now, op);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;

    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++)
            cin>>arr[i][j];
    }

    dfs(0, 0, arr[0][0] - '0', ' ');

    cout<<max_an<<" "<<min_an;

    //문제유형 : dfs
}
