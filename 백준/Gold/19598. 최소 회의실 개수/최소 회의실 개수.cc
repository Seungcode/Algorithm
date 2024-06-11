#include <iostream>
#include <queue>

using namespace std;

int N;
priority_queue <int, vector<int>, greater<>> arr;
priority_queue <pair<int, int>, vector<pair<int, int>>, greater<>> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;

    for(int i = 0; i<N; i++){
        int a, b;
        cin>>a>>b;
        q.push({a, b});
    }

    while(!q.empty()){
        if(arr.empty())
            arr.push(q.top().second);
        else if(arr.top()<=q.top().first){
            arr.pop();
            arr.push(q.top().second);
        }
        else{
            arr.push(q.top().second);
        }
        q.pop();
    }

    cout<<arr.size();
    //문제유형 :greedy
}
