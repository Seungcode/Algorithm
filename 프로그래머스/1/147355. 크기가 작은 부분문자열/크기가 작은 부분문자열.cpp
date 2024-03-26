#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    
    //앞에서부터 차례대로 해당 숫자의 길이만큼 잘라서 확인
    for(int i = 0; i<t.length()-(p.length()-1); i++){
        string temp = t.substr(i, p.length());
        if(temp <= p)
            answer++;
    }
    
    //문제 유형 : 구현(문자열)
    //시간복잡도 : O(N) -> O(10,000)이 최대
    return answer;
}