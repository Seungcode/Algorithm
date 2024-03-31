#include <string>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    //3진법 저장
    string three = "";
    
    //바로 앞뒤반전으로 저장하기
    while(n>0){
        three+=n%3 + '0';
        n = n/3;
    }
    
    //자릿수 계산용 변수
    int cnt = 1;
    
    //정답 도출
    for(int i= three.length()-1; i>=0; i--){
        answer += (three[i] - '0') * cnt;
        cnt *= 3;
    }
    
    //문제유형 : 구현(문자열)
    
    return answer;
}