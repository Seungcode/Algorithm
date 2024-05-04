#include <string>
#include <vector>
#include <sstream>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    for(int i = 0; i<s.length(); i++){
        
        stack <char> arr;
        int cnt = 0;
        s += s[0];
        s = s.substr(1, s.length()-1);
        
        for(auto j : s){
            if(j == '{' || j == '(' || j == '[')
                arr.push(j);
            else{
                if(arr.empty()) break;
                else if(arr.top() == '(')
                    if(j!=')') break;
                else if(arr.top() == '{')
                    if(j!='}') break;
                else
                    if(j!=']') break;
                arr.pop();
            }
            cnt++;
        }
        
        if(cnt == s.length() && arr.empty()) answer++;
    }
    
    //문제유형 : stack
    return answer;
}