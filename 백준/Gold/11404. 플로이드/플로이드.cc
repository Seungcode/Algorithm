#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

//도시의 수, 버스 노선의 수
int N, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;

    //도시가 1~N까지 있기때문에 배열을 N+1까지!
    vector<vector<int>> arr;
    arr.resize(N+1, vector<int>(N+1, INT_MAX));

    //간선 입력 받음 -> 노선이 하나가 아닐 수 있기 때문에 최소값으로!
    for(int i = 0; i<M; i++){
        int start, end, cost;
        cin>>start>>end>>cost;
        arr[start][end] = min(arr[start][end], cost);
    }

    //해당 도시 -> 해당 도시는 비용이 안들기 때문에 0으로
    for(int i = 1; i<=N; i++){
        arr[i][i] = 0;
    }

    //플로이드-워셜 알고리즘 사용 -> 남은 빈칸 채우기
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            for(int z = 1; z<=N; z++){
                if(arr[j][i]!=INT_MAX && arr[i][z]!=INT_MAX){
                    arr[j][z] = min(arr[j][z], arr[j][i] + arr[i][z]);
                }
            }
        }
    }

    //값 출력 -> 맥스값일 경우 -> 0으로 출력
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            if(arr[i][j] == INT_MAX)
                cout<<0<<" ";
            else
                cout<<arr[i][j]<<" ";
        }
        cout<<'\n';
    }
    
    //문제유형 : 플로이드-워셜 최단 경로 찾기
    return 0;
}