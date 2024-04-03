#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    //완주 여부 체킹용
    map <string, int> player;
    map<string, int> arr;
    
    for(auto i : participant)
        arr[i]++;
    
    //완주한 사람 체크
    for(auto i : completion)
        player[i] ++;
    
    //만약 완주하지 못한 사람이 있으면 멈춤
    for(auto i : participant){
        if(player[i]!=arr[i]){
            answer = i;
            break;
        }
    }
    
    //문제유형 : 해시
    return answer;
}