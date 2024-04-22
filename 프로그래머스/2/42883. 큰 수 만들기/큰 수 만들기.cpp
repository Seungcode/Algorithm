#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    //변수 선언
    deque <char> arr;
    int idx = k;
    
    //반복
    for(int i = 0; i<number.length(); i++){
        if(idx == 0) {
            arr.push_back(number[i]);
            continue;
        }
        
        //비어있을 경우를 제외하고 앞글자에서 지울 수 있는 값 찾기
        if(!arr.empty()){
            while(true){
                //환경 상 지울 수 없을 때
                if(idx == 0 || arr.empty()) break;
                
                //지울 수 있을 경우
                if(number[i] - '0' > arr.back() - '0'){
                   idx--;
                   arr.pop_back();
                }
                
                //앞의 수가 더 클 경우
                else break;
            }
        }
        arr.push_back(number[i]);
    }
    
    //정답 만들기
    for(int i = 0; i<number.length()-k; i++){
        answer+=arr.front();
        arr.pop_front();
    }

    return answer;
}