#include <string>
#include <cmath>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long answer = -1;
    
    //제곱근 구하기
    double temp = sqrt(n);
    
    // 제곱근이 정수일 경우
    if (fmod(temp, 1.0) == 0.0)
        answer = pow(temp + 1, 2);
    
    
    //문제유형 : 수학
    return answer;
}