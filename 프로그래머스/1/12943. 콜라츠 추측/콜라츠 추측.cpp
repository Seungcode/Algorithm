#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    
    //자료형 변경
    long long int temp = num;
    
    //정해진 루트 수행
    for(int i =0; i<500; i++){
        if(temp==1)
            break;
        else if(temp%2==0)
            temp = temp/2;
        else
            temp = temp*3 + 1;
        answer++;
    }
    
    //불가능할 경우
    if(temp!=1)
        answer = -1;
    
    //문제유형 : 구현
    
    return answer;
}