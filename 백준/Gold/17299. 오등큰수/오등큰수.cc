#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int N;
int arr[1000001] = {0, };
int answer[1000001] = {0, };
int cnt[1000001] = {0, };
stack<pair<int, int>> st;

void solution(){
    for(int i = 0; i<N; i++) cnt[arr[i]] ++;

    for(int i = N-1; i>=0; i--){
       while(!st.empty()){
           if(cnt[arr[i]] >= st.top().second) st.pop();
           else{
               answer[i] = st.top().first;
               st.push({arr[i], cnt[arr[i]]});
               break;
           }
       }
       if(st.empty()) {
           answer[i] = -1;
           st.push({arr[i], cnt[arr[i]]});
       }
    }

    for(int i = 0; i<N; i++) cout<<answer[i]<<" ";
}

//입력받기
void input(){
    cin>>N;

    for(int i = 0; i<N; i++) cin>>arr[i];

    solution();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();

    return 0;
}