#include <vector>
#include <iostream>
using namespace std;

int MOD = 20170805;

/*고려할 점
방향 전환이 안되는 2의 경우 들어올 때 뿐 아니라 나갈 때에도 통행에 제한이 있다!
즉, 들어온 방향 뿐 아니라 나갈 방향도 하나의 고려 포인트가 될 수 있다.
*/

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    
    int arr[501][501][2] = {0, };
    
    for(int i = 0; i<m; i++){
        if(city_map[i][0] == 1) break;
        arr[i][0][0] = 1;
    }
    
    for(int i = 0; i<n; i++){
        if(city_map[0][i] == 1) break;
        arr[0][i][1] = 1;
    }
    
    for(int i = 1; i<m; i++){
        for(int j = 1; j<n; j++){
            if(city_map[i-1][j] == 0){
                arr[i][j][0] += (arr[i-1][j][0] + arr[i-1][j][1])%MOD;
            }
            if(city_map[i][j-1] == 0){
                arr[i][j][1] += (arr[i][j-1][0] + arr[i][j-1][1])%MOD;
            }
            if(city_map[i-1][j] == 2){
                arr[i][j][0] += (arr[i-1][j][0])%MOD;
            }
            if(city_map[i][j-1] == 2){
                arr[i][j][1] += (arr[i][j-1][1])%MOD;
            }
            arr[i][j][0] %= MOD;
            arr[i][j][1] %= MOD;
        }
    }
    
    return (arr[m-1][n-1][0] + arr[m-1][n-1][1])%MOD;
}