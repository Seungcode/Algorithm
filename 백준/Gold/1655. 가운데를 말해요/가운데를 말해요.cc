#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;

    priority_queue<int, vector<int>, greater<int>> q_after;
    priority_queue<int> q;
    queue <int> temp;

    for(int i = 0; i<N; i++){
        //값 입력받기
        int a;
        cin>>a;

        //값 넣어주기
        if(q.empty()){
            q.push(a);
        }
        else if(q.top() < a)
            q_after.push(a);
        else
            q.push(a);
        
        //중간값을 q.top으로 유지하기
        if(q_after.size() > q.size()){
            q.push(q_after.top());
            q_after.pop();
        }
        else if(q.size() > q_after.size()+1){
            q_after.push(q.top());
            q.pop();
        }
        
        cout<<q.top()<<"\n";
    }

    //문제유형 : 우선순위큐
    return 0;
}
