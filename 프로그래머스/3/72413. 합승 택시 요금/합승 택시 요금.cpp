#include <string>
#include <vector>

using namespace std;

#define MAX 100000*200+1
int arr[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    
    //배열 초기화
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++) arr[i][j] = MAX;
        arr[i][i] = 0;
    }
    
    //초기 비용 정리
    for(auto i : fares){
        arr[i[0]][i[1]] = i[2];
        arr[i[1]][i[0]] = i[2];
    }
    
    //다익스트라 알고리즘 -> 200이내이기 때문에 우선순위 큐를 사용하지 않아도 괜찮을 듯 
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int z = 1; z <= n; z++)
                if(arr[j][i] != MAX && arr[i][z] != MAX) arr[j][z] = min(arr[j][z], arr[j][i] + arr[i][z]);
        }
    }
    
    //비용 초기화
    answer = arr[s][a] + arr[s][b];
    
    //최소 비용 구하기
    for(int i = 1; i<=n; i++)
        answer = min(answer, arr[s][i] + arr[i][a] + arr[i][b]);
    
    return answer;
}