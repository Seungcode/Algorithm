#include <iostream>

using namespace std;

string a, b;
int answer = 0;
int arr[4001][4001] = {0, };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>a>>b;

    for(int i = 1; i<=a.length(); i++){
        for(int j = 1; j<=b.length(); j++){
            if(a[i-1] == b[j-1]) arr[i][j] = arr[i-1][j-1] + 1;
            else arr[i][j] = 0;
            answer = max(answer, arr[i][j]);
        }
    }

    cout<<answer;
}