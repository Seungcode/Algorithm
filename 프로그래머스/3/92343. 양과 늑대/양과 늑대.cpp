#include <string>
#include <vector>

using namespace std;

vector<int> sheep;
vector<int> arr[17];
int max_s = 0;
bool visited[17] = {false, };

void dfs(int sh, int wo, int now){
    //양의 수 및 조건 체크
    if(sheep[now] == 0) sh ++;
    else wo++;
    
    if(sh <= wo) return;
    
    max_s = max(sh, max_s);
    
    //갈 수 있는 위치 체크
    for(auto i : arr[now]){
        visited[i] = true;
    }
    
    //갈 수 있는 곳들 들리기
    for(int i = 0; i<sheep.size(); i++){
        if(!visited[i]) continue;
        visited[i] = false;
        dfs(sh, wo, i);
        visited[i] = true;
    }
    
    //다시 가 ㄹ수 없음 표시
    for(auto i : arr[now]){
        visited[i] = false;
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    sheep = info;
    
    for(auto i : edges)
        arr[i[0]].push_back(i[1]);
    
    dfs(0, 0, 0);
    
    return max_s;
}