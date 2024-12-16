#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

/* 
돌아오는 부분을 고려해야하는가? 
-> 어짜피 돌아오는 길은 같은 길을 지나와도 상관이 없음
-> 가는 길만 고려하면 될 듯?
*/

vector<pair<int, int>> node[50001];
int visited[50001];
map<int, int> gate;
map<int, int> mountain;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    
    answer.push_back(50001);
    answer.push_back(10000001);
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    for(int i = 1; i<=n; i++) visited[i] = 10000001;
    
    for(auto i : gates) gate[i] ++;
    
    for(auto i : summits) mountain[i] ++;
    
    for(auto i : paths){
        node[i[1]].push_back({i[0], i[2]});
        node[i[0]].push_back({i[1], i[2]});
        if(gate[i[0]] != 0) {
            visited[i[0]] = i[2];
            q.push({i[2], i[0]});
        }
        if(gate[i[1]] != 0) {
            visited[i[1]] = i[2];
            q.push({i[2], i[1]});
        }
    }
    
    while(!q.empty()){
        pair<int, int> now = q.top();
        q.pop();
        
        if(mountain[now.second] != 0){
            continue;
        }
        
        if(now.first > visited[now.second]) continue;
        
        for(auto i : node[now.second]){
            if(gate[i.first] != 0) continue;
            if(max(i.second, now.first) < visited[i.first]){
                visited[i.first] = max(i.second, now.first);
                q.push({max(i.second, now.first), i.first});
            }
        }
    }
    
    sort(summits.begin(), summits.end());
    for(auto i : summits){
        if(answer[1] > visited[i]){
            answer[0] = i;
            answer[1] = visited[i];
        }
    }
    
    return answer;
}