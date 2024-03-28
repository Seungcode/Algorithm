#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    //로또 당첨 번호를 넣을 map
    map<int, int> lotto;
    
    //변수 초기화
    int best = 0;
    int worst = 0;
    
    //등수
    int score[6] = {6, 5, 4, 3, 2, 1};
    
    //당첨번호 마스킹
    for(auto i : win_nums)
        lotto[i] = 1;
    
    //당첨일 경우 -> 둘 다 +1, 0일 경우 -> 최선의 결과만 +1
    for(auto i : lottos){
        if(i==0)
            best++;
        else if(lotto[i] == 1){
            best++;
            worst++;
        }
    }
    
    //정답 만들기
    answer.push_back(best < 2 ? 6 : score[best-1]);
    answer.push_back(worst < 2 ? 6 : score[worst-1]);
    
    //문제유형 : 구현
    
    return answer;
}
