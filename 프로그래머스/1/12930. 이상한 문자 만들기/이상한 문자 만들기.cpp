#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    //단어별 인덱스
    int index = 0;
    
    for(int i = 0; i<s.length(); i++){
        //공백일 경우
        if(s[i] == ' '){
            index = 0;
            answer += " ";
        }
        
        //아닐 경우 
        else{
            //짝수라면
            if(index%2==0)
                answer += toupper(s[i]);
            //홀수라면
            else
                answer += tolower(s[i]);
            index++;
        }
    }
    
    //문제유형 : 문자열
    return answer;
}