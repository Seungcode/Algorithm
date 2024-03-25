#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    
    //각 인물 별 그리움 점수를 담을 map 선언
    map<string, int> memory;
    
    //그리움 점수 할당
    for(int i = 0; i<name.size(); i++){
        memory[name[i]] = yearning[i];
    }
    
    //추억 점수 계산 -> map에서 초기에 할당 안된 값은 0으로 저장 -> 추가 처리 필요 X
    for(int i = 0; i<photo.size(); i++){
        int cnt = 0;
        for(auto j : photo[i]){
            cnt+=memory[j];
        }
        answer.push_back(cnt);
    }
    return answer;
}