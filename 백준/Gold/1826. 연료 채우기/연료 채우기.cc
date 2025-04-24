#include <iostream>
#include <queue>

using namespace std;

int N, L, P;
int arr[1000001] = {0, };

void input() {
    cin>>N;

    for(int i = 0; i<N; i++){
        int a, b;
        cin>>a>>b;
        arr[a] = max(arr[a], b);
    }

    cin>>L>>P;
}

void solution() {
    input();

    priority_queue<int> q;
    int answer = 0;

    for(int i = 0; i<=L; i++){
        while(P<i){
            if(q.empty()){
                cout<<-1;
                return;
            }
            P += q.top();
            q.pop();
            answer ++;
        }
        if(arr[i] != 0) q.push(arr[i]);
    }

    cout<<answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}
