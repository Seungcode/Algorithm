#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    
    
    //피타고라스정리를 사용해서 가능한 좌표 구하기
    for(int i = 1; i<=r2; i++){
        if(i<r1)
            answer += floor(sqrt(pow(r2, 2) - pow(i, 2))) - ceil(sqrt(pow(r1, 2) - pow(i, 2))) + 1;
        else
            answer += floor(sqrt(pow(r2, 2) - pow(i, 2))) + 1;
    }
    
    //문제유형 : 수학
    return answer*4;
}