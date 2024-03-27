#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    //현재 문자, 현재 문자가 나온 수, 다른 문자가 나온 수
    char now = s[0];
    int cnt_now = 1;
    int cnt_else = 0;
    
    //나온 수가 같을 때 answer에 1 더하고, 아닐 경우 각 상황에 따라 수 변수 변경
    for(int i = 1; i<s.length(); i++){
        if(cnt_now==cnt_else){
            cnt_else = 0;
            cnt_now = 1;
            now = s[i];
            answer++;
        }
        else if(now == s[i])
            cnt_now++;
        else
            cnt_else++;
    }
    
    //문제유형 : 구현(문자열)
    
    return answer+1;
}