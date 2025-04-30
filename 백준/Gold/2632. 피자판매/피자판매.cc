#include <iostream>
#include <unordered_map>

using namespace std;

int S, M, N, answer = 0;
int A[2001];
int B[2001];
unordered_map<int, int> prefixSumA;

void input() {
    cin>>S>>M>>N;

    int temp = 0;
    for(int i = 0; i<M; i++){
        cin>>A[i];
        A[i+M] = A[i];
        temp += A[i];
    }
    prefixSumA[temp] ++;

    for(int i = 0; i<N; i++){
        cin>>B[i];
        B[i+N] = B[i];
    }
}

void makePrefixA(){
    for(int i = 0; i<M; i++){
        int temp = 0;
        for(int j = 0; j<M-1; j++){
            temp += A[i+j];
            if(temp > S) break;
            prefixSumA[temp] ++;
        }
    }

    answer += prefixSumA[S];
}

void makePrefixB(){
    for(int i = 0; i<N; i++){
        int temp = 0;
        for(int j = 0; j<N-1; j++){
            temp += B[i+j];
            if(temp > S) break;
            if(temp == S) answer++;
            answer += prefixSumA[S - temp];
        }
        if(i == N-1) {
            temp += B[N - 2];
            if(temp == S) answer++;
            answer += prefixSumA[S - temp];
        }
    }
}

void solution() {
    input();

    makePrefixA();
    makePrefixB();

    cout<<answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}
