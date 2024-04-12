#include <string>
#include <vector>
#include <stack>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    //배달 갯수 관련 변수 선언
    int d = 0;
    int p = 0;
    //몇 번 왕복해야하는지
    int cnt = 0;
    
    for(int i = n-1; i>=0; i--){
        //현재 위치에서 옮길 짐들 / 수거할 짐들을 빼줌
        d -= deliveries[i];
        p -= pickups[i];
        
        //하나라도 옮겨야한다면
        while(d<0 || p<0){
            //더해주고 -> 더하는 만큼 움직여야함
            d +=cap;
            p += cap;
            cnt++;
        }
        
        //계산
        answer += (i+1)*2*cnt;
        cnt = 0;
    }
    
    //문제유형 : 그리디 알고리즘
    
    return answer;
}