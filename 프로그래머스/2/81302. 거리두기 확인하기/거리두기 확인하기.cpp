#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<vector<string>> arr;

bool bfs(int idx, int x, int y){
    bool visited[5][5] = {false, };
    queue<pair<int, int>> q;
    
    q.push({x, y});
    visited[x][y] = true;
    
    while(!q.empty()){
        pair<int, int> now = q.front();
        q.pop();
        
        for(int i = 0; i<4; i++){
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];
            
            if(nx < 0 || ny < 0 || nx>=5 || ny >=5) continue;
            if(arr[idx][nx][ny] == 'X' || abs(x - nx) + abs(y - ny) > 2 || visited[nx][ny]) continue;
            
            if(arr[idx][nx][ny] == 'P') return false;
            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
    
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(int i = 0; i<5; i++) answer.push_back(1);
    
    arr = places;
    
    for(int i = 0; i<5; i++){
        for(int j = 0; j<5; j++){
            for(int z = 0; z<5; z++){
                if(arr[i][j][z] == 'P') {
                    if(!bfs(i, j, z)) answer[i] = 0;
                }
            }
            if(answer[i] == 0) break;
        }
    }
    
    return answer;
}