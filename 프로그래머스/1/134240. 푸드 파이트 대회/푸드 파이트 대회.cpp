#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    
    //첫번째 사람이 먹게되는 양
    for(int i = 1; i<food.size(); i++){
        for(int j = 0; j<food[i]/2; j++){
            answer+=i+'0';
        }
    }
    
    //물
    answer+='0';
    
    //두번째 사람이 먹게되는 양
    for(int i = food.size()-1; i>0; i--){
        for(int j = 0; j<food[i]/2; j++){
            answer+=i+'0';
        }
    }
    
    //문제유형 : 구현
    return answer;
}