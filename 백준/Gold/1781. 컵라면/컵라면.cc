#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N;
priority_queue<int, vector<int>, greater<>> arr;
vector<pair<int, int>> hw;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first != b.first)
        return a.first < b.first;
    else
        return a.second > b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;

    for(int i = 0; i<N; i++){
        int a, b;
        cin>>a>>b;
        hw.push_back({a, b});
    }

    sort(hw.begin(), hw.end(), cmp);

    for(auto i : hw){
        if(i.first > arr.size()) arr.push(i.second);
        else if(i.second > arr.top()){
            arr.pop();
            arr.push(i.second);
        }
    }

    int answer = 0;
    while(!arr.empty()) {
        answer += arr.top();
        arr.pop();
    }

    cout<<answer;

    return 0;

    //문제유형 : priority queue + greedy
}
