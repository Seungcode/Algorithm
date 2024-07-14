#include <iostream>
#include <map>

using namespace std;

int N, M, K, answer = 0;
string arr[51];
map<string, int> light;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;

    for(int i = 0; i<N; i++) {
        cin >> arr[i];
        light[arr[i]] ++;
    }

    cin>>K;

    for(auto i : light){
        int temp = 0;
        for(auto j : i.first) if(j=='0') temp++;
        if(temp <= K && temp%2 == K%2) answer = max(answer, i.second);
    }

    cout<<answer;
}
