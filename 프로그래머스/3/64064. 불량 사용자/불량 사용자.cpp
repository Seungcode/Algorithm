#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

//중복을 없애기 위해 set 자료구조 사용
set<set<string>> an;
map<string, int> visited;
vector<string> arr[9];
vector<string> cor[9];
int m_idx = 0;

void find(int x, set<string> a){
    //최종 결과 set에 넣어주기
    if(x == m_idx) {
        an.insert(a);
        return;
    }
    
    //경우 고려
    for(auto i : cor[x]){
        if(visited[i] == 0){
            visited[i] = 1;
            a.insert(i);
            find(x + 1, a);
            a.erase(i);
            visited[i] = 0;
        }
    }
    
    return;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    m_idx = banned_id.size();
    
    //이름 정리
    for(auto i : user_id) arr[i.length()].push_back(i);
    
    //정지 아이디 매칭
    for(int i = 0; i<banned_id.size(); i++){
        int cnt = 0;
        for(int j = 0; j <arr[banned_id[i].length()].size(); j++){
            int idx = 0;
            
            //이름 확인하며 성립하는지 확인 
            while(idx < arr[banned_id[i].length()][j].length()){
                if(banned_id[i][idx] != '*'){
                    if(arr[banned_id[i].length()][j][idx] != banned_id[i][idx]) break;
                }
                idx++;
            }
            
            //만일 성립한다면
            if(idx == arr[banned_id[i].length()][j].length()) 
                cor[i].push_back(arr[banned_id[i].length()][j]);
        }
    }
    
    set<string> a;
    find(0, a);
    
    return an.size();
}