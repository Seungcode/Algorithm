#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N, M;
string arr[15];

void permu(string a, int i, int cnt){
    if(a.length() == N && cnt >= 1 && N-cnt >= 2){
        cout<<a<<endl;
        return;
    }

    if(i >= M) return;

    if(arr[i+1]=="a"||arr[i+1]=="e"||arr[i+1]=="i"||arr[i+1]=="o"||arr[i+1]=="u") permu(a+arr[i+1], i+1, cnt+1);
    else permu(a+arr[i+1], i+1, cnt);
    permu(a, i+1, cnt);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;

    for(int i = 0; i<M; i++)
        cin>>arr[i];

    sort(arr, arr+M);

    for(int i = 0; i<M; i++) {
        if (arr[i] == "a" || arr[i] == "e" || arr[i] == "i" || arr[i] == "o" || arr[i] == "u") permu(arr[i], i, 1);
        else permu(arr[i], i, 0);
    }

    //문제유형 : 백트레킹
}
