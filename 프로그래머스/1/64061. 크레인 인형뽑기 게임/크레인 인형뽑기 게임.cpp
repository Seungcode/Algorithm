#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    vector<int> dolls;
    
    for(auto i : moves){
        for(int j = 0; j<board.size(); j++){
            if(board[j][i-1] != 0) {
                if(!dolls.empty()){
                    if(board[j][i-1] == dolls.back()){
                        answer+=2;
                        dolls.pop_back();
                        board[j][i-1] = 0;
                        break;
                    }
                }
                dolls.push_back(board[j][i-1]);
                board[j][i-1] = 0;
                break;
            }
        }
    }
    return answer;
}