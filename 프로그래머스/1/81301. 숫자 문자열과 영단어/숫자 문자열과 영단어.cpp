#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    //영단어별로 길이 체크
    int len_num[10] = {4, 3, 3, 5, 4, 4, 3, 5, 5, 4};
    
    
    for(int i = 0; i<s.length();){
        int temp = -1;
        //시작 알파벳이 단독일 경우 먼저 처리
        if(s[i] == 'z')
            temp = 0;
        else if(s[i] == 'o')
            temp = 1;
        else if(s[i] == 'n')
            temp = 9;
        else if(s[i] == 'e')
            temp = 8;
        //두 개일 경우 처리
        else if(s[i] == 't')
            s[i+1] == 'w' ? temp = 2 : temp = 3;
        else if(s[i] == 'f')
            s[i+1] == 'o' ? temp = 4 : temp = 5;
        else if(s[i] == 's')
            s[i+1] == 'i' ? temp = 6 : temp = 7;
        
        //temp가 음수이면 -> 숫자대로 들어감
        if(temp < 0){
            temp = s[i] - '0';
            i++;
        }
        //숫자가 영어로 들어갔다면 -> 영단어 길이만큼 패스
        else
            i+=len_num[temp];
        
        //숫자 저장
        answer = answer*10 + temp;
    }
    
    //문제유형 : 구현(문자열)
    return answer;
}