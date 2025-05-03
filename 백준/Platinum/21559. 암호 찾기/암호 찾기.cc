#include <iostream>
#include <unordered_map>

using namespace std;

int N, K, answer = 0;
string A, B;
unordered_map<string, int> cnt;

void input() {
    cin>>N>>K>>A>>B;
}

void makeCnt(){
    for(int i = K-1; i < N; i++){
        string temp = A.substr(i-K+1, K);
        cnt[temp] ++;
    }

    for(int i = K-1; i < N; i++){
        string temp = B.substr(i-K+1, K);
        if(cnt[temp] != 0){
            answer++;
            cnt[temp] = 0;
        }
    }
}

void solution() {
    input();

    makeCnt();

    cout<<answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}
