#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int N;
int ans = 0;
int temp = 0;
pair<int, int> arr[8];

void bt(int idx){
    if(idx > N) return;

    for(int i = 0; i<N; i++){
        if(arr[idx].first <= 0) bt(idx+1);
        else if(arr[i].first <= 0 || i == idx) continue;
        else{
            arr[idx].first -= arr[i].second;
            arr[i].first -= arr[idx].second;
            bt(idx+1);
            arr[idx].first += arr[i].second;
            arr[i].first += arr[idx].second;
        }
    }

    for(int i = 0; i<N; i++)
        if(arr[i].first <= 0) temp++;
    ans = max(ans, temp);
    temp = 0;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;

    for(int i = 0; i<N; i++){
        int a, b;
        cin>>a>>b;
        arr[i] = {a, b};
    }

    bt(0);
    
    cout<<ans;
    //문제유형 : 백트
}
