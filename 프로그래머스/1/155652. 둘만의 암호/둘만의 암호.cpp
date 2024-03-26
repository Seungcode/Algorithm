#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    
    //건너뛸 문자 체크할 map 선언
    map <char, int> skip_al;
    char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    
    //건너뛸 문자는 1로 체크
    for(auto i : skip)
        skip_al[i] = 1;
    
    //한 문자씩 건너뛰면서 알파벳 찾기
    for(auto i : s){
        int cnt = i-'a';
        int now = 0;
        while(true){
            cnt++;
            if(skip_al[alpha[cnt%26]]==0)
                now++;
            if(now == index)
                break;
        }
        answer += alpha[cnt%26];
    }
    
    //문제 타입 : 구현
    return answer;
}