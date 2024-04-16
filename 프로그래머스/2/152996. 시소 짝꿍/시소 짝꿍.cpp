#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

//무게 저장용 변수 선언
int w[4001] = {0, };
map <int, int> cnt;

long long solution(vector<int> weights) {
    long long answer = 0;
    
    //작은 수부터 정렬
    sort(weights.begin(), weights.end());
    
    for(auto i : weights){
        //이미 같은 무게가 있을 경우
        if(cnt[i] > 0) answer += cnt[i];
        
        //배수들도 확인해주기
        for(int j = 2; j<=4; j++){
            answer += w[i*j] - cnt[i];
            w[i*j]++;
        }
        
        //현재 위치에 더해주기
        cnt[i]++;
    }
    
    //문제 유형 : 정렬 + 브루트포스
    
    return answer;
}