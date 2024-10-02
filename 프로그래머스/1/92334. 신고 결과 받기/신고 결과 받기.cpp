#include <string>
#include <vector>
#include <map>

using namespace std;

bool visited[1001][1001] = {false, };
map<string, int> cnt;
map<string, int> index;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    answer.resize(id_list.size(), 0);
    
    for(int i = 0; i<id_list.size(); i++) index[id_list[i]] = i;
    
    //신고 현황 관리
    for(auto i : report){
        string send = "";
        string receive = "";
        
        for(auto j : i){
            if(j == ' ') break;
            send += j;
        }
        
        for(int j = i.length()-1; j>0; j--){
            if(i[j] == ' ') break;
            receive = i[j] + receive;
        }
        
        if(!visited[index[receive]][index[send]]){
            visited[index[receive]][index[send]] = true;
            cnt[receive]++;
        }
    }
    
    //문자 받을 수 계산
    for(auto i : cnt){
        if(i.second >= k){
            for(int j = 0; j < id_list.size(); j++){
                if(visited[index[i.first]][j]) answer[j] ++;
            }
        }
    }
    
    return answer;
}