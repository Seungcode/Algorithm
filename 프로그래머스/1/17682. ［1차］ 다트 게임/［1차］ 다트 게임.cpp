#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    
    //점수 저장
    vector<int> arr;
    
    for(int i = 0; i<dartResult.size();){
        
        //스코어 계산
        int score = dartResult[i] - '0';
        i++;
        
        if(dartResult[i] == '0'){
            score = 10;
            i++;
        }
        
        //보너스 및 옵션 계산
        while(dartResult[i] - '0' > 9 || dartResult[i] - '0' < 0 && i<dartResult.size()){
            //보너스 계산
            if(dartResult[i] == 'S') score = score;
            else if(dartResult[i] == 'D') score *= score;
            else if(dartResult[i] == 'T') score = score*score*score;
            
            //옵션 계산
            else if(dartResult[i] == '*'){
                if(!arr.empty()) arr[arr.size() - 1] = arr[arr.size() - 1]*2;
                score *= 2;
            }
            else score *= -1;
            i++;
        }
        
        arr.push_back(score);
    }
    
    //총 점 계산
    for(auto i : arr) answer += i;
    
    return answer;
}