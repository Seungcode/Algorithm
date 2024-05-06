#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int N, M;
int answer = INT_MAX;
vector<vector<int>> arr;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    arr.resize(N+1, vector<int>(N+1, INT_MAX));

    for(int i = 0; i<M; i++){
        int a, b, c;
        cin>>a>>b>>c;
        arr[a][b] = min(arr[a][b], c);
    }

    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            for(int z = 1; z<=N; z++){
                if(arr[j][i] != INT_MAX && arr[i][z] != INT_MAX)
                    arr[j][z] = min(arr[j][z], arr[j][i] + arr[i][z]);
            }
        }
    }

    for(int i = 1; i<=N; i++) 
        answer = min(answer, arr[i][i]);

    if(answer == INT_MAX)
        cout<<-1;
    else
        cout<<answer;
    
    //문제유형 : 플로이드 - 워셜

    return 0;
}
