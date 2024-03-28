#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    //옹알이 가능 여부 확인
    for(auto i : babbling){
        //같은 단어가 연속되는 것을 막기 위한 변수
        int flag = 0;
        answer++;
        
        //해당 단어가 가능한지 확인 -> 4가지 옹알이 내에 걸리면서 연속되지 않는 경우가 아니라면 옹알이 불가
        for(int j = 0; j<i.length(); j++){
            if(i.substr(j, 3) == "aya" && flag != 1){
                flag = 1;
                j+=2;
            }
            else if(i.substr(j, 2) == "ye" && flag != 2){
                flag = 2;
                j++;
            }
            else if(i.substr(j, 3) == "woo" && flag != 3){
                flag = 3;
                j+=2;
            }
            else if(i.substr(j, 2) == "ma" && flag != 4){
                flag = 4;
                j++;
            }
            else{
                answer--;
                break;
            }
        }
    }
    
    //문제유형 : 구현
    
    return answer;
}