#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int TC;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //테스트케이스 갯수 입력
    cin>>TC;

    for(int i = 0; i<TC; i++){
        //도시 수와 도로, 웜홀 수 입력
        int N, M, W;
        cin>>N>>M>>W;
        vector<vector<int>> arr;
        arr.resize(N+1, vector<int>(N+1, INT_MAX));
        
        //도시 초기화 -> 만일 끝나고 0보다 작다 -> 시간 거슬러감
        for(int j = 0; j<=N; j++){
            arr[j][j] = 0;
        }
        
        //도로 입력 -> 양방향으로 입력받고 도로가 많을 수도 있으므로 최소값만 저장 -> 최소값이 거슬러가는데 유리하기 때문
        for(int j = 0; j<M; j++){
            int S, E, T;
            cin>>S>>E>>T;
            arr[S][E] = min(arr[S][E], T);
            arr[E][S] = min(arr[E][S], T);
        }
        
        //웜홀 입력 -> 시간을 더 많이 거슬러가는 것 위주로 저장
        for(int j = 0; j<W; j++){
            int S, E, T;
            cin>>S>>E>>T;
            arr[S][E] = min(arr[S][E], -T);
        }
        
        //플로이드-워셜 사용
        for(int k = 1; k<=N; k++){
            for(int z = 1; z<=N; z++){
                for(int y = 1; y<=N; y++){
                    if(arr[z][k]!=INT_MAX && arr[k][y] != INT_MAX)
                        arr[z][y] = min(arr[z][y], arr[z][k] + arr[k][y]);
                }
            }
        }
        
        //결과값 출력
        int cnt = 0;
        for(int j = 1; j<=N; j++){
            if(arr[j][j]<0){
                cout<<"YES"<<"\n";
                break;
            }
            else cnt++;
        }
        if(cnt==N)
            cout<<"NO"<<'\n';
        
        //문제유형 : 플로이드 - 워셜 최소값 찾기
    }
}