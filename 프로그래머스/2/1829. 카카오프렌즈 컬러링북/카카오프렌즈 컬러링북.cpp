#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> arr;
bool visited[101][101];


int bfs(int x, int y){
    queue<pair<int, int>> q;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    
    int cnt = 1;
    
    q.push({x, y});
    
    while(!q.empty()){
        pair<int, int> now = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];
            if(nx<0 || ny<0 || nx >= arr.size() || ny >= arr[0].size()) continue;
            if(visited[nx][ny]) continue;
            if(arr[nx][ny] != arr[now.first][now.second]) continue;
            visited[nx][ny] = true;
            q.push({nx, ny});
            cnt++;
        }
    }
    return cnt;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    vector<int> answer(2);
    arr = picture;
    
    for(int i = 0; i<m; i++){
        for(int j = 0; j < n; j++) visited[i][j] = false;
    }
    
    for(int i = 0; i<m; i++){
        for(int j = 0; j < n; j++){
            if(picture[i][j] != 0 && !visited[i][j]){
                number_of_area++;
                visited[i][j] = true;
                max_size_of_one_area = max(max_size_of_one_area, bfs(i, j));
            }
        }
    }
    
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    
    return answer;
}