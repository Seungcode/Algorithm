#include <iostream>
using namespace std;

int arr[1001] = {0, 1, 3, };
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a;
    cin>>a;
    for(int i = 3; i<=a; i++){
        arr[i] = (arr[i-1] + 2*arr[i-2])%10007;
    }
    cout<<arr[a];
}
