#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    //체육복의 유무를 확인하기 위한 map 선언
    map <int, int> cloth;
    
    //잃어버린 사람과 여분이 있는 사람 표시
    for(auto i : lost)
        cloth[i]--;
    for(auto i : reserve)
        cloth[i] ++;
    
    //답 구하기 -> 이전 사람은 내가 아니면 쓸 수 없음 -> 우선 탐색
    for(int i = 1; i<=n; i++){
        if(cloth[i]==0 || cloth[i]==1)
            answer++;
        else{
            if(cloth[i-1] == 1){
                cloth[i]++;
                cloth[i-1]--;
                answer++;
            }
            else if(cloth[i+1] == 1){
                cloth[i]++;
                cloth[i+1]--;
                answer++;
            }
        }
    }
    
    //문제 유형 : 그리디
    
    return answer;
}