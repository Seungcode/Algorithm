#include <string>
#include <vector>

using namespace std;

int arr[1002][1002] = {0, };

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    
    //건물 공격 & 치료 계산
    for(auto i : skill){
        int degree = i[5];
        
        if(i[0] == 1)
            degree *= -1;
        
        arr[i[1]+1][i[2]+1] += degree;
        arr[i[3]+2][i[4]+2] += degree;
        arr[i[3]+2][i[2]+1] -= degree;
        arr[i[1]+1][i[4]+2] -= degree;
    }
    
    //누적합 구하기
    for(int i = 1; i<=board.size(); i++){
        for(int j = 1; j<=board[0].size(); j++)
            arr[i][j] += arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
    }
    
    //망가지지 않은 건물 수 구하기
    for(int i = 0; i<board.size(); i++){
        for(int j = 0; j<board[0].size(); j++)
            if(board[i][j] + arr[i+1][j+1] > 0) answer++;
    }
    
    return answer;
}