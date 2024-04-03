#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    //정답 배열의 사이즈 지정
    answer.resize(arr1.size(), vector<int>(arr1[0].size()));
    
    //같은 위치의 값끼리 더해서 배열에 할당
    for(int i = 0; i<arr1.size(); i++){
        for(int j = 0; j<arr1[i].size(); j++){
            answer[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    
    //문제유형 : 구현 
    return answer;
}