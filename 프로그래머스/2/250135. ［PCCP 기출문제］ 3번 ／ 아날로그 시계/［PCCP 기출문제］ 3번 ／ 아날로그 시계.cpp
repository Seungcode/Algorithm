#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0;
    
    //시작 각도 세팅 -> Int 형으로 계산하기 위해 값 변화
    int s_h = (h1*60*60 + m1*60 + s1)%(360*120);
    int s_m = (m1*60 + s1)*(12)%(360*120);
    int s_s = (s1)*(720)%(360*120);
    
    //시작점에서 알람이 울릴 경우 계산
    if(s_s == s_h || s_s == s_m)
        answer++;
    
    //12시 정각을 지나는 경우 -> 3개가 동시에 만나기 때문에 1빼줌
    if(h1*60*60 + m1*60 + s1<12*60*60 && h2*60*60 + m2*60 + s2>=12*60*60)
        answer--;
    
    //계산
    for(int i = h1*60*60 + m1*60 + s1; i<h2*60*60 + m2*60 + s2; i++){
        //시침과 초침이 만날 경우
        if(s_h > s_s && s_s+720>=s_h+1){
            answer++;
        }
            
        //분침과 초침이 만날 경우
        if(s_m > s_s && s_s+720>=s_m+12){
            answer++;
        }
        
        //각도 증가
        s_s = (s_s + 720)%(360*120);
        s_m = (s_m + 12)%(360*120);
        s_h = (s_h + 1)%(360*120);
    }
    
    //문제유형 : 구현
    return answer;
}