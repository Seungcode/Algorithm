#include <string>
#include <map>
#include <iostream>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    double mul = 0, sum = 0;
    
    //합집합과 교집합을 찾기 위함
    map<string, int> exist;
    map<string, int> exist2;
    
    //1번 문자열 정리
    for(int i = 0; i<str1.length()-1; i++){
        //알파벳이 아닌 경우 -> 패스
        if(tolower(str1[i]) - 'a' > 25 || tolower(str1[i]) - 'a' < 0 || 
           tolower(str1[i+1]) - 'a' > 25 || tolower(str1[i+1]) - 'a' < 0) 
            continue;
        
        //문자열 만들기 -> 소문자로 통일해서 만들기
        string temp  = "";
        temp += tolower(str1[i]);
        temp += tolower(str1[i+1]);
        exist[temp] ++;
    }
    
    //2번 문자열 정리
    for(int i = 0; i<str2.length()-1; i++){
        if(tolower(str2[i]) - 'a' > 25 || tolower(str2[i]) - 'a' < 0 || 
           tolower(str2[i+1]) - 'a' > 25 || tolower(str2[i+1]) - 'a' < 0) 
            continue;
        
        string temp = "";
        temp += tolower(str2[i]);
        temp += tolower(str2[i+1]);
        exist2[temp] ++;
    }
    
    //합집합과 교집합 확인
    for(auto i : exist){
        //교집합 및 합집합 중 여러개 있는 경우 확인
        if(exist[i.first] && exist2[i.first]){
            sum += max(exist[i.first], exist2[i.first]);
            mul += min(exist[i.first], exist2[i.first]);
        }
        else sum += i.second;
    }
    
    //합집합에 집계되어지지 않은 내용 집계
    for(auto i : exist2){
        if(exist[i.first] == 0 && i.second){
            sum += i.second;
        }
    }
    
    //유사도 계산
    if(mul == 0 && sum == 0) answer = 65536;    
    else answer = (mul / sum) * 65536;
    
    return answer;
}