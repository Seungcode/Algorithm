#include <string>
#include <vector>
#include <queue>
using namespace std;

//방문 여부 확인 배열
bool visited[1000001] = {false, };

int solution(int x, int y, int n) {
    //변수 설정
    int answer = -1;
    queue<pair<int, int>> q;
    q.push({x, 0});
    
    //bfs 실행 -> 원하는 값 나오면 stop
    while(!q.empty()){
        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(now == y){
            answer = cnt;
            return answer;
        }
        if(now+n <= y){
            if(!visited[now+n]){
                visited[now+n] = true;
                q.push({now+n, cnt + 1});
            }
        }
        if(now*2 <= y){
            if(!visited[now*2]){
                visited[now*2] = true;
                q.push({now*2, cnt + 1});
            }
        }
        if(now*3 <= y){
            if(!visited[now*3]){
                visited[now*3] = true;
                q.push({now*3, cnt + 1});
            }
        }
    }
    
    //문제유형 : bfs
    return answer;
}