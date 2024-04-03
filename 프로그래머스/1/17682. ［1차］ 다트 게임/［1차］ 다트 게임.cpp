#include <string>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    
    //이전값과 현재 값을 저장할 변수
    int before = 0;
    int now = 0;
    
    //계산
    for(int i = 0; i<dartResult.length(); i++){
        
        //숫자가 나왔을 때 -> 이전 숫자가 있을 경우 -> 음수이거나 혹은 계산한 값이 10보다 클 경우 -> before과 now 갱신
        if(dartResult[i] - '0' >= 0 && dartResult[i] - '0' <= 9){
            if(now < 0){
                before = now;
                now = 0;
            }
            now = now*10 + (dartResult[i] - '0');
            if(now>10){
                before = now/10;
                now = now%10;
            }
        }
        //보너스 값 계산
        else if(dartResult[i] =='S' || dartResult[i] == 'D' || dartResult[i] =='T'){
            if(dartResult[i] == 'S')
                now = now;
            else if(dartResult[i] == 'D')
                now = now*now;
            else if(dartResult[i] == 'T')
                now = now*now*now;
            answer += now;
        }
        //옵션 값 계산
        else{
            if(dartResult[i] == '*'){
                answer = answer-now;
                now = now*2;
                answer+= before + now;
            }
            else if(dartResult[i] == '#'){
                answer = answer - now;
                now = -1*now;
                answer += now;
            }
        }
    }
    
    //문제유형 : 구현
    
    return answer;
}
