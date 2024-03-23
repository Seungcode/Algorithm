#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    //선물 주고 받은 갯수 저장소
    int result[51][51] = {0, };
    map<string, int> name;
    map<string, int> give;
    //이름별로 인덱스 번호 부여 -> map사용
    for(int i = 0; i<friends.size(); i++)
        name[friends[i]] = i;
    //선물별로 주고 받은 사람 정리
    for(auto i : gifts){
        string a = "";
        string b = "";
        int cnt = 0;
        //준 사람
        while(true){
            if(i[cnt]==' '){
                cnt++;
                break;
            }
            a += i[cnt];
            cnt++;
        }
        //받은 사람
        while(cnt<i.length()){
            b += i[cnt];
            cnt++;
        }
        give[a]++;
        give[b]--;
        result[name[a]][name[b]]++;
    }
    
    //다음달 받을 선물 갯수 정리
    for(auto i : friends){
        int cnt = 0;
        for(auto j : friends){
            if((result[name[i]][name[j]] == 0 && result[name[j]][name[i]] == 0)||result[name[i]][name[j]] == result[name[j]][name[i]]){
                if(give[i]>give[j])
                    cnt++;
            }
            else if(result[name[i]][name[j]] > result[name[j]][name[i]])
                cnt++;
        }
        answer = max(answer, cnt);
    }
    return answer;
}