#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> neg;
vector<int> pos;

void input(){
    cin>>N>>M;

    for(int i = 0; i<N; i++) {
        int a;
        cin>>a;
        if(a < 0) neg.push_back(abs(a));
        else pos.push_back(a);
    }

    sort(neg.begin(), neg.end(), greater<>());
    sort(pos.begin(), pos.end(), greater<>());
}

void solution() {
    input();

    int answer = 0;

    for(int i = 0; i < neg.size(); i++){
        int now = neg[i];

        i += M-1;
        if(i >= neg.size()) i = neg.size() - 1;

        answer += now * 2;
    }

    for(int i = 0; i < pos.size(); i++){
        int now = pos[i];

        i += M-1;
        if(i >= pos.size()) i = pos.size() - 1;

        answer += now * 2;
    }

    if(!pos.empty() && !neg.empty())
        answer -= max(pos[0], neg[0]);
    else answer -= pos.empty() ? neg[0] : pos[0];

    cout<<answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solution();
}
