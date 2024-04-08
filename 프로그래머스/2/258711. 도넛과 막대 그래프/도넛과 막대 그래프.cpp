#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;
bool visited[1000001] = {false, };
vector<int> graph[1000001];

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    
    //시작점을 구하기 위함 -> 들어오는 간선이 없다면 그 점이 시작점일 것
    map<int, int> start;
    
    //간선 정리
    for(auto i : edges){
        graph[i[0]].push_back(i[1]);
        start[i[1]]++;
    }
    
    //시작점 구하고 나머지 값 초기화하기
    for(int i = 1; i<=1000000; i++){
        if(start[i]==0 && graph[i].size()>=2){
            answer.push_back(i);
            break;
        }
    }
    answer.push_back(0);
    answer.push_back(0);
    answer.push_back(0);
    
    //어떤 모양인지 구하기
    for(int i = 0; i<graph[answer[0]].size(); i++){
        queue <pair<int, int>> q;
        
        //시작점 넣어주기
        q.push({answer[0], graph[answer[0]][i]});
        
        //bfs 시작
        while(!q.empty()){
            int now = q.front().first;
            int end = q.front().second;
            q.pop();
            
            //더 가는 간선이 없다 -> 직선모양
            if(graph[end].size()==0) answer[2]++;
            
            //나가는 간선이 2개이다 -> 8자 모양
            if(graph[end].size()==2){
                answer[3]++;
                break;
            }
            
            //그 외의 경우
            else{
                for(auto j : graph[end]){
                    //시작점으로 돌아올 경우 -> 간선이 2개가 아니고 시작점 -> 도넛 모양
                    if(j == graph[answer[0]][i]){
                        answer[1]++;
                        break;
                    }
                    
                    //아닐 경우 추가 탐색
                    if(visited[j]==false){
                        visited[j] = true;
                        q.push({end, j});
                    }
                }
            }
        }
    }
    
    //문제유형 : bfs + 구현
    return answer;
}