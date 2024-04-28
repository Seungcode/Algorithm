#include <string>
#include <map>
#include <cctype>
#include <iostream>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    
    map<string, int> news1;
    map<string, int> news2;
    
    double cnt = 0.0;
    double cnt_old = 0.0;
    
    //집합 만들기
    for(int i = 0; i<str1.length()-1; i++){
        string temp = "";
        temp += tolower(str1[i]);
        temp += tolower(str1[i+1]);
        if(temp[0] - 'a' >= 0 && temp[0] - 'a'<26 && temp[1] - 'a' >= 0 && temp[1] - 'a'<26)
            news1[temp]++;
    }
    
    for(int i = 0; i<str2.length()-1; i++){
        string temp = "";
        temp += tolower(str2[i]);
        temp += tolower(str2[i+1]);
        if(temp[0] - 'a' >= 0 && temp[0] - 'a'<26 && temp[1] - 'a' >= 0 && temp[1] - 'a'<26)
            news2[temp]++;
    }
    
    //교집합 및 합집합 구하기
    for(int i = 0; i<str1.length()-1; i++){
        string temp = "";
        temp += tolower(str1[i]);
        temp += tolower(str1[i+1]);
        cnt+=max(news1[temp], news2[temp]);
        cnt_old+=min(news1[temp], news2[temp]);
        //해당 처리가 있어야 같은 문자가 여러번 카운팅 되어지지 않음
        news1[temp] = 0;
        news2[temp] = 0;
    }
    
    for(int i = 0; i<str2.length()-1; i++){
        string temp = "";
        temp += tolower(str2[i]);
        temp += tolower(str2[i+1]);
        if(news1[temp]==0)
            cnt+=news2[temp];
        news2[temp] = 0;
    }
    
    //답 구하기
    if(cnt == 0)
        answer = 65536;
    else
        answer = (int)((cnt_old/cnt) * 65536);
    
    //문제유형 : 문자열 + 구현 + 해싱
    
    return answer;
}