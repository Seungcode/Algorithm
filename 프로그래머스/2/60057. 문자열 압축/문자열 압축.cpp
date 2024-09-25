#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    //기초 셋팅 = 압축한 글은 항상 글의 길이보다는 짧거나 같음
    int answer = s.length();
    
    for(int i = 1; i<s.length(); i++){
        //현재 길이만큼을 기준으로 압축했을 경우 결과
        int tem_answer = 0;
        string tem_s = s;
        
        //남는 문자열이 있을 경우 -> 뒷부분은 그냥 마지막에 추가해 줌
        for(int j = 0; j < s.length() % i; j++){
            tem_answer ++;
            tem_s.pop_back();
        }
        
        for(int j = 0; j<=tem_s.length()-i; j += i){
            //지금과 다음 i칸 까지의 문자열을 비교 -> 같으면 압축
            string now = tem_s.substr(j, i);
            string temp = tem_s.substr(j + i, i);
            
            //같은 문자열이 몇 번 반복되는지 확인
            int cnt = 1; 
            while(now == temp && j<=tem_s.length()-i){
                cnt ++;
                j += i;
                temp = tem_s.substr(j + i, i);
            }
            
            //만약 반복되지 않는다면
            if(cnt == 1) tem_answer += i;
            //반복된다면 -> 숫자의 길이 + 문자열의 길이
            else {
                while(cnt != 0){
                    tem_answer ++;
                    cnt = cnt / 10;
                }   
                tem_answer += i;
            }
        }
        
        //가장 작은 길이 가져가기
        answer = min(tem_answer, answer);
    }
    
    return answer;
}