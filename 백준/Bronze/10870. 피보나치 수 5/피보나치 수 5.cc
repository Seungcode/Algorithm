#include <iostream>

using namespace std;

int main() {
    int a;
    cin>>a;
    
    int arr[21] = {0, };
    arr[1] = 1;
    
    for(int i = 2; i <= a; i++) arr[i] = arr[i-1] + arr[i-2];
    
    cout<<arr[a];
}