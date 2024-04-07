#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    
    //시작점과 끝점 계산
    int start = a;
    int end = b;
    
    if(a>b) {
        start = b;
        end = a;
    }
    
    //값 구하기
    for(int i = start; i<=end; i++)
        answer+=i;
    
    //문제유형 : 구현
    return answer;
}