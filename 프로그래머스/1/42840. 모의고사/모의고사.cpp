#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    //정답으로 찍는 번호
    int first[5] = {1, 2, 3, 4, 5};
    int second[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int third[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    //점수
    int first_score = 0;
    int second_score = 0;
    int third_score = 0;
    
    //번호가 맞으면 점수 증가
    for(int i = 0; i<answers.size(); i++){
        if(first[i%5] == answers[i]) first_score++;
        if(second[i%8] == answers[i]) second_score++;
        if(third[i%10] == answers[i]) third_score++;
    }
    
    //최대값과 같거나 크면 값 넣어줌
    if(max(max(first_score, second_score), third_score) <= first_score) answer.push_back(1);
    if(max(max(first_score, second_score), third_score) <= second_score) answer.push_back(2);
    if(max(max(first_score, second_score), third_score) <= third_score) answer.push_back(3);
    
    //문제유형 : 구현
    
    return answer;
}