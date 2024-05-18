#include<vector>
#include<queue>

using namespace std;

vector<vector<int> > arr;
bool visited[101][101] = {false, };
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int a, b;

int bfs(int x, int y){
    queue<pair<int, pair<int, int>>> q;
    q.push({1, {x, y}});
    while(!q.empty()){
        x = q.front().second.first;
        y = q.front().second.second;
        int cnt = q.front().first;
        q.pop();
        if(a==x && b==y) return cnt;
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || ny<0 || nx>a || ny>b) continue;
            if(!visited[nx][ny] && arr[nx][ny] == 1){
                visited[nx][ny] = true;
                q.push({cnt+1, {nx, ny}});
            }
        }
    }
    return -1;
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    arr = maps;
    a = maps.size()-1;
    b = maps[0].size()-1;
    
    answer = bfs(0, 0);
    return answer;
    
    //문제 유형 : bfs
}