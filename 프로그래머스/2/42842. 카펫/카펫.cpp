#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    //모서리 빼주기
    brown -= 4;
    
    //가로가 더 길기 때문에 제곱근까지 반복
    for(int i = 1; i<=sqrt(yellow); i++){
        if(yellow%i != 0) continue;
        //조건에 성립할 경우 종료
        if(i*2 + (yellow/i)*2 == brown){
            answer.push_back(yellow/i + 2);
            answer.push_back(i+2);
            break;
        }
    }
    
    //문제유형 : 완전탐색 + 수학
    return answer;
}