#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, answer = 0;
vector<pair<int, int>> ready;
priority_queue<int, vector<int>, greater<>> now;

void input(){
    cin>>N;
    for(int i = 0; i<N; i++){
        int a, b, c;
        cin>>a>>b>>c;
        ready.push_back({b, c});
    }
    sort(ready.begin(), ready.end());
}

void solution() {
    input();

    for(auto i : ready){
        if(now.empty()) now.push(i.second);
        else{
            if(now.top() <= i.first){
                now.pop();
            }
            now.push(i.second);
        }
        answer = answer > now.size() ? answer : now.size();
    }
    cout<<answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solution();
}
