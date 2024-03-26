#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    //약관 정리용 map 정의
    map <char, int> ter;
    
    //오늘 날짜 정리
    int t_cnt = stoi(today.substr(0, 4))*12*28 + stoi(today.substr(5, 2))*28 + stoi(today.substr(8, 2));
    
    //약관 기간 정리
    for(auto i : terms){
        int temp = 0;
        for(int j = 2; j<i.length(); j++){
            temp = temp*10+(i[j]-'0');
        }
        ter[i[0]] = temp;
    }
    
    //날짜를 기준으로 조건에 부합하는지 확인
    int cnt = 1;
    for(auto i : privacies){
        int user_cnt = stoi(i.substr(0, 4))*12*28 + stoi(i.substr(5, 2))*28 + stoi(i.substr(8, 2)) + ter[i[i.length()-1]]*28;
        
        if(t_cnt>=user_cnt)
            answer.push_back(cnt);
        
        cnt++;
        }
    
    //시간복잡도 O(N) -> 최대 O(100)
    return answer;
}