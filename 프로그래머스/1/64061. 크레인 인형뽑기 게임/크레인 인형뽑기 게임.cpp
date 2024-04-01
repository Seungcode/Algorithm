#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    //erase를 사용하기 위해 deque로 선언
    deque <int> arr;
    
    //크레인의 위치를 바꿔가며 확인
    for(auto i : moves){
        //0이 아닌게 나오면 데큐에 넣어줌
        for(int j = 0; j<board.size(); j++){
            if(board[j][i-1]!=0){
                arr.push_back(board[j][i-1]);
                board[j][i-1] = 0;
                break;
            }
        }
        
        //2개 이상의 인형이 들어갔을 경우 같은지 확인하고 같으면 끝에 두 개를 지워주고 값을 증가시킴
        if(arr.size()>=2){
            if(arr[arr.size()-1] == arr[arr.size()-2]){
                arr.pop_back();
                arr.pop_back();
                answer+=2;
            }
        }
    }
    
    //문제유형 : 구현
    return answer;
}