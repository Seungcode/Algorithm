#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    //변수 생성 -> 0 / 1 인덱스 만들어서 바로 더해도 상관없음
    int cnt = 0;
    int zero = 0;
    
    while(s.length()!=1){
        //0 제거하고 담을 문자열
        string a = "";
        //이진 변환을 담을 문자열
        string temp = "";
        cnt++;
        
        //0 제거
        for(int i = 0; i<s.length(); i++){
            if(s[i]!='0') a+=s[i];
        }
        zero+=s.length() - a.length();
        
        //s초기화
        s = "";
        
        //이진 변환
        int now = a.length();
        while(now!=0){
            temp += to_string(now%2);
            now /= 2;
        }
        
        for(int i = 0; i<temp.length(); i++)
            s+=temp[temp.length()-1-i];
    }
    
    //답 넣어주기
    answer.push_back(cnt);
    answer.push_back(zero);
    
    //문제유형 : 문자열 구현
    return answer;
}