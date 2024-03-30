#include <string>
#include <vector>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    
    //X와 Y가 각각 어떤 숫자의 구성으로 이루어져있는지를 담을 배열
    int for_X[10] = {0, };
    int for_Y[10] = {0, };
    
    //각 숫자 구성 저장
    for(int i = 0; i<X.length(); i++)
        for_X[X[i]-'0']++;
    for(int i = 0; i<Y.length(); i++)
        for_Y[Y[i]-'0']++;
    
    //높은 수부터 시작하여 더 적게 나온 갯수만큼 문자열에 추가
    for(int i = 9; i>=0; i--){
        for(int j = 0; j<min(for_X[i], for_Y[i]); j++)
            answer += ((char)i+'0');
    }
    
    //0일때와 공백일때를 예외로 처리
    if(answer[0] == '0')
        answer = '0';
    if(answer == "")
        answer = "-1";
    
    //문제유형 : 구현
    
    return answer;
}