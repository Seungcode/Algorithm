#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    answer += toupper(s[0]);
    
    for(int i = 1; i<s.length(); i++){
        if(s[i-1]==' '){
            answer += toupper(s[i]);
        }
        else answer += tolower(s[i]);
    }
    
    //문제유형 : 문자열
    
    return answer;
}