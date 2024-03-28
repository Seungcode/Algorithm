#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    //정렬
    sort(score.rbegin(), score.rend());
    
    //큰 값부터 사용하는게 무조건 이득 -> 역순으로 돌면서 사과 가격 측정
    for(int i = m-1; i<score.size();){
        answer+=score[i]*m;
        i+=m;
    }
    
    //문제유형 : 구현 + 약간의 그리디?
    
    return answer;
}