#include <string>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

struct road{
    pair<int, int> before;
    pair<int, int> now;
    int cost;
    int direct;
    
    bool operator<(const road& other) const {
        return other.cost < cost;
    }
};

priority_queue<road> arr;
int visited[26][26][4];

int solution(vector<vector<int>> board) {
    int answer = INT_MAX;
    
    for(int i = 0; i<25; i++){
        for(int j = 0; j<25; j++) {
            for(int x = 0; x<4; x++) visited[i][j][x] = INT_MAX;
        }
    }
    
    if(board[1][0] == 0){
        visited[1][0][0] = 100;
        arr.push({{0, 0}, {1, 0}, 100, 0});
    }
    
    if(board[0][1] == 0) {
        visited[0][1][2] = 100;
        arr.push({{0, 0}, {0, 1}, 100, 2});
    }
    
    while(!arr.empty()){
        pair<int, int> now = arr.top().now;
        pair<int, int> before = arr.top().before;
        int cost = arr.top().cost;
        int direct = arr.top().direct;
        arr.pop();
        
        if(visited[now.first][now.second][direct] < cost) continue;
        
        for(int i = 0; i<4; i++){
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];
            int temp_cost = cost + 100;
            if(nx < 0 || ny < 0 || nx >= board.size() || ny >= board[0].size()) continue;
            if(board[nx][ny] == 1) continue;
            if(nx != before.first && ny != before.second) temp_cost += 500;
            if(temp_cost < visited[nx][ny][i]) {
                visited[nx][ny][i] = temp_cost;
                arr.push({now, {nx, ny}, temp_cost, i});
            }
        }
    }
    
    for(int i = 0; i<4; i++) 
        answer = min(answer, visited[board.size()-1][board[0].size()-1][i]);
    
    return answer;
}