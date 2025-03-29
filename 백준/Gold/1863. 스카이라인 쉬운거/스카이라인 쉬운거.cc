#include <iostream>
#include <stack>

using namespace std;

int N;

void input() {
    cin>>N;
}

void solution() {
    input();

    stack<int> s;
    int answer = 0;
    for(int i = 0; i <= N; i++){
        int x, y;

        if(i==N) y = 0;
        else cin>>x>>y;

        while(!s.empty()){
            if(s.top() < y) break;
            else if(s.top() != y) answer ++;
            s.pop();
        }

        s.push(y);
    }

    cout<<answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}