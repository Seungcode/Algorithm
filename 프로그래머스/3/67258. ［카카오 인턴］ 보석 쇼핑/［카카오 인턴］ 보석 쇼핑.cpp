#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

set<string> cnt;
map<string, int> now;
int n_cnt = 1;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    
    answer.push_back(0);
    answer.push_back(gems.size());
    
    for(auto i : gems) cnt.insert(i);
    
    int start = 0;
    int end = 0;
    
    now[gems[end]] ++;
    
    while(end < gems.size()){
        
        if (n_cnt < cnt.size()){
            end ++;
            if(end >= gems.size()) break;
            now[gems[end]] ++;
            if(now[gems[end]] == 1) n_cnt++;
        }
        
        if(n_cnt == cnt.size()){
            if(end - start < answer[1] - answer[0]){
                answer[0] = start + 1;
                answer[1] = end + 1;
            }
            now[gems[start]]--;
            if(now[gems[start]] == 0) n_cnt --;
            start ++;
        }
    }
    
    return answer;
}