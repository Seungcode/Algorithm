#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    
    //부호에 따라 값 연산
    for(int i = 0; i<signs.size(); i++)
        signs[i] == true ? answer += absolutes[i] : answer-= absolutes[i];
    
    //문제유형 : 구현
    return answer;
}