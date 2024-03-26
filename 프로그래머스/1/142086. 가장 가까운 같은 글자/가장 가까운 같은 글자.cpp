#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    //글자가 나온 최근 위치를 업데이트 하기 위해 map선언
    map<char, int> first;
    
    //현재 글자에 대해 연산 진행 -> 첫 칸에 나온 글자는 또 0이 들어가기 때문에 전체적으로 1 더해서 할당
    for(int i = 0; i<s.length(); i++){
        if(first[s[i]] == 0)
            answer.push_back(-1);
        else
            answer.push_back(i+1-first[s[i]]);
        first[s[i]] = i+1;
    }
    
    //문제 유형 : 구현(해시)
    return answer;
}