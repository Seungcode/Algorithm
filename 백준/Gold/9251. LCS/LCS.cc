#include <iostream>

using namespace std;

//문자열의 최대 길이 -> 1000
int arr[1002][1002] = {0, };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a, b;
    cin>>a>>b;

    //같을 경우 -> 대각선 이전 값 + 1, 아닐 경우 -> 최대값 그대로
    for(int i = 0; i<a.length(); i++) {
        for(int j = 0; j<b.length(); j++){
            if(a[i]==b[j])
                arr[i+1][j+1] = arr[i][j] + 1;
            else
                arr[i+1][j+1] = max(arr[i][j+1], arr[i+1][j]);
        }
    }

    cout<<arr[a.length()][b.length()];
    
    //문제유형 : dp
    
    return 0;
}