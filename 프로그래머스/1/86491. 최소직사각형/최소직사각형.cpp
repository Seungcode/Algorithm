#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    //두 변 중 더 긴 변과 짧은 변을 저장할 변수 -> 가로 세로는 바뀔 수 있으므로
    int long_len = 0;
    int short_len = 0;
    
    //각 변과 현재 명함의 길이를 비교하며 갱신
    for(auto i : sizes){
        long_len = max(long_len, max(i[0], i[1]));
        short_len = max(short_len, min(i[0], i[1]));
    }
    
    //결과값 생성
    answer = long_len*short_len;
    
    //문제유형 : 구현(완탐)
    
    return answer;
}