#include <string>
#include <vector>
#include <iostream>

using namespace std;

//진수 변환
char arr[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    //현재 위치와 수
    int now = 1;
    int cnt = 0;
    
    while(true){
        int temp = cnt;
        string temp_s = "";
        
        //n진수 변환
        while(true){
            temp_s += arr[temp%n];
            temp = temp/n;
            
            if(temp == 0) break;
        }
        
        //내 위치에 오면 추가 -> 역순으로 해줘야 우리가 생각하는 n진수임
        for(int i = temp_s.length()-1; i>=0; i--){
            if(now%m == p || (m==p && now%m == 0)) {
                answer += temp_s[i];
                //길이만큼 다 구했다면 -> for문 벗어남
                if(answer.length() == t) break;
            }
            now++;
        }
        
        //길이만큼 다 구했다면 -> 종료하기 위해 while문 벗어남
        if(answer.length() == t) break;
        
        cnt++;
    }
    
    return answer;
}