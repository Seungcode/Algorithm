#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;

int N, M;
vector<pair<int, int>> arr[501];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;
    queue <pair<int, int>> q;
    vector<long long int> result(N+1, INT_MAX);

    for(int i = 0; i<M; i++){
        int start, end, cost;
        cin>>start>>end>>cost;
        arr[start].push_back({end, cost});
        if(start == 1)
            q.push({end, cost});
    }

    //시작은 무조건 1부터임
    result[1] = 0;

    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            for(auto z : arr[j]){
                if(result[j] != INT_MAX && result[z.first] > result[j] + z.second){
                    result[z.first] = result[j] + z.second;
                    if(i==N){
                        cout<<-1;
                        return 0;
                    }
                }
            }
        }
    }

    for(int i = 2; i<=N; i++){
        if(result[i] == INT_MAX)
            cout<<-1<<"\n";
        else
            cout<<result[i]<<"\n";
    }

    //문제유형 : 벨만포드

    return 0;
}
