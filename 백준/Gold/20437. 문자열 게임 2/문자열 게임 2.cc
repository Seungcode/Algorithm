#include <iostream>
#include <vector>

using namespace std;

int N, T;
string sen;
vector<int> alpha[26];

void input() {
    cin>>T;
}

void init(){
    for(auto &i : alpha){
        i.clear();
    }
}

void solution() {
    input();

    for(int i = 0; i<T; i++){
        init();
        pair<int, int> answer = {10001, 0};

        cin>>sen>>N;

        for(int j = 0; j < sen.length(); j++){
            alpha[sen[j] - 'a'].push_back(j);
        }

        for(auto j : alpha){
            if(j.size() >= N){
                for(int r = 0; r <= j.size() - N; r++){
                    answer = {min(answer.first, j[r+N-1] - j[r] + 1), max(answer.second, j[r+N-1] - j[r] + 1)};
                }
            }
        }
        if(answer.first == 10001 && answer.second == 0) cout<<-1<<endl;
        else cout<<answer.first<<" "<<answer.second<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}