#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;

int makeTime(string a){
    int res = 0;
    string time = a.substr(0, 2);
    string minute = a.substr(3, 2);
    string sec = a.substr(6, 2);
    string msec = a.substr(9, 3);
    res += (stoi(time) * 60 * 60 *1000) + (stoi(minute) * 60 * 1000) + (stoi(sec) * 1000) + stoi(msec);
    return res;
}

void input() {
    cin>>N;

    for(int i = 0; i<N; i++){
        string a, b;
        cin>>a>>b;
        q.push({makeTime(a), makeTime(b)});
    }
}

void solution() {
    input();

    priority_queue<int, vector<int>, greater<>> arr;
    int answer = 0;

    while(!q.empty()){
        pair<int, int> now = q.top();
        q.pop();

        arr.push(now.second);

        while(!arr.empty()){
            if(arr.top() < now.first) arr.pop();
            else break;
        }

        answer = answer < arr.size() ? arr.size() : answer;
    }
    cout<<answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}
