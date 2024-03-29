#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    
    //n이 a보다 작을 때까지 반복 -> 몫*병의 갯수를 하면 현재 받을 수 있는 병의 수 -> 나눈 값에 나머지 병을 더하면 새로 병을 받으러 간다.
    while(true){
        if(n<a)
            break;
        answer += (n/a)*b;
        n = (n/a)*b + n%a;
    }
    
    //문제유형 : 구현
    
    return answer;
}