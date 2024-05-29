#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N;
priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, greater<pair<long long int, long long int>>> arr;
priority_queue<long long int, vector<long long int>, greater<long long int>> result;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;

    for(int i = 1; i<=N; i++){
        long long int s, t;
        cin>>s>>t;
        arr.push({s, t});
    }

    while(!arr.empty()){
        if(result.empty())
            result.push(arr.top().second);
        else if(result.top() <= arr.top().first){
            result.pop();
            result.push(arr.top().second);
        }
        else
            result.push(arr.top().second);
        arr.pop();
    }

    cout<<result.size();
    return 0;

    //문제유형 : greedy
}
