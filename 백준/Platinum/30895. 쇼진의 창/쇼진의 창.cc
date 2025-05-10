#include <iostream>

using namespace std;

int N, M, K;
long long up, under, answer;
pair<long long, long long> diff;
void input(){
    cin>>N>>M>>K;
    M += N;
}

void solution() {
    input();

    up = (K/N + (K%N == 0 ? 0 : 1));
    under = (K/M + (K%M == 0 ? 0 : 1));

    diff = {up, under};
    answer = K;

    long long index = K % M == 0 ? K+1 : (K / M + 1) * M + 1;

    for(int i = 0; i<=M; i++){

        long long tempUp = index%N == 0 ? index/N : index/N + 1;;
        long long tempUnder = index%M == 0 ? index/M : index/M + 1;

        if(tempUp*diff.second < diff.first * tempUnder){
            diff = {tempUp, tempUnder};
            answer = index;
        }

        index += M;
    }

    cout<<answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solution();
}
