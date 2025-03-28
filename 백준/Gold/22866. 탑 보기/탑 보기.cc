#include <iostream>
#include <stack>

using namespace std;

int N;
int arr[100001] = {0, };
int cnt[100001] = {0, };
int nearBy[100001] = {0, };

void input() {
    cin>>N;
    for(int i = 0; i<N; i++){
        cin>>arr[i];
        nearBy[i] = -1;
    }
}

void before(){
    stack <pair<int, int>> s;

    for(int i = 0; i<N; i++) {
        while (!s.empty()) {
            if(arr[i] < s.top().second) break;
            s.pop();
        }
        cnt[i] += s.size();
        if(!s.empty())nearBy[i] = s.top().first;
        s.push({i, arr[i]});
    }
}

void after(){
    stack <pair<int, int>> s;

    for(int i = N-1; i>=0; i--) {
        while (!s.empty()) {
            if(arr[i] < s.top().second) break;
            s.pop();
        }
        cnt[i] += s.size();
        if(!s.empty()){
            if(nearBy[i] == -1) nearBy[i] = s.top().first;
            else{
                if((i - nearBy[i]) > (s.top().first - i)) nearBy[i] = s.top().first;
            }
        }
        s.push({i, arr[i]});
    }
}

void solution() {
    input();

    before();
    after();

    for(int i = 0; i < N; i++){
        cout<<cnt[i]<<" ";
        if(cnt[i] == 0) cout<<"\n";
        else cout<<nearBy[i]+1<<"\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}