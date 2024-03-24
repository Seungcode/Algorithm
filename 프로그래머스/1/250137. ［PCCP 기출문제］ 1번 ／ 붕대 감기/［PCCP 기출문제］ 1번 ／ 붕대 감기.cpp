#include <string>
#include <vector>

using namespace std;
//틀렸던 이유 : 추가회복시에도 회복 성공 시간을 0으로 초기화 했어야하는데 이를 고려하지 못함 -> 제한사항 고려의 부족

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    //초기 값을 주어진 체력만큼으로 초기화
    int answer = health;
    
    //현재 인덱스 값과 붕대 감은 초를 저장 할 변수
    int cnt = 0;
    int now = 0;
    
    //범위 : 처음 초 - 마지막 공격 시까지
    for(int i = attacks[0][0]; i<= attacks[attacks.size()-1][0]; i++){
        //공격일 경우
        if(i==attacks[cnt][0]){
            answer -= attacks[cnt][1];
            cnt++;
            now = 0;
        }
        //공격이 아닐 경우 -> 붕대 감기
        else{
            now++;
            answer+=bandage[1];
        }
        //붕대를 정해진 초 동안 감았을 경우
        if(now == bandage[0]){
            answer += bandage[2];
            now = 0;
        }
        //체력이 최대 체력 이상으로 올라갔을 경우
        if(answer > health){
            answer  = health;
        }
        //게임 아웃일 경우
        if(answer <= 0){
            return -1;
        }
    }
    return answer;
}