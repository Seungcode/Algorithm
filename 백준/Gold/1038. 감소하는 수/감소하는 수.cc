#include <iostream>
#include <queue>

using namespace std;

int N, now = -1;

void desc_num(){
    queue<long long> q;
    for(int i = 0; i<10; i++){
        now++;
        q.push(i);
        if(now==N){
            cout<<i;
            exit(0);
        }
    }
    while(!q.empty()){
        long long x = q.front();
        q.pop();
        for(int i = 0; i<x%10; i++){
            now++;
            q.push(x*10 + i);
            if(now == N){
                cout<<x*10 + i;
                exit(0);
            }
        }
    }
}

int main() {
    cin>>N;
    desc_num();
    cout<<-1;

    //백트래킹
}
