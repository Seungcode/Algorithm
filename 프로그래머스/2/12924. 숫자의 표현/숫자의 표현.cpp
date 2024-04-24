#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    //시작 포인터 설정
    int first = 1;
    int second = 1;
    int temp = first;
    
    //누적합 구하기
    while(second<=n){
        if(temp == n){
            answer ++;
            second ++;
            temp += second;
        }
        else if(temp < n){
            second ++;
            temp += second;
        }
        else{
            temp -= first;
            first++;
        }
    }
    
    //문제유형 : 투포인터
    
    return answer;
}