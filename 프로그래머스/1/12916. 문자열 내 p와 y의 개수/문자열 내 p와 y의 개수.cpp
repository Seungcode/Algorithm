#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    //문자의 갯수를 확인
    int p = 0;
    int y = 0;

    //문자의 갯수 확인
    for(int i = 0; i<s.length(); i++){
        if(s[i] == 'p' || s[i] == 'P')
            p++;
        if(s[i] == 'y' || s[i] == 'Y')
            y++;
    }
    
    //다를 경우 false 
    if(p!=y) answer = false;
    
    //문제유형 : 문자열
    
    return answer;
}