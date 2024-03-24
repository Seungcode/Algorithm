#include <string>
#include <vector>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    int width = board[0].size();
    int height = board.size();
    for(int i = 0; i < 4; i++){
        int temp_h = h + dy[i];
        int temp_w = w + dx[i];
        if(temp_h >= width || temp_h < 0 || temp_w < 0 || temp_w >= height)
            continue;
        if(board[h][w]==board[temp_h][temp_w])
            answer++;
    }
    return answer;
}