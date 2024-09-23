#include <string>
#include <vector>
#include <iostream>
using namespace std;

string make_word(string p){
    string answer = "";
    
    if(p.empty()) return answer;
    
    string temp = "";
    
    int cnt = 0;
    bool flag = true;
    string u = "";
    
    if(p[0] == '(') cnt = 1;
    else cnt = -1;
    u += p[0];
    
    for(int i = 1; i<p.length(); i++){
        if(cnt == 0) break;;
        if(cnt < 0) flag = false;
        if(p[i] == '(') cnt++;
        else cnt--;
        u += p[i];
    }

    for(int i = 0; i<u.length(); i++) p.erase(p.begin());

    if(flag) answer += u + make_word(p);
    
    else if(!flag) {
        answer += '(' + make_word(p) + ')';
        for(int i = 1; i < u.length()-1;  i++) answer += u[i] == ')' ? '(' : ')';
    }
    return answer;
}

string solution(string p) {
    string answer = "";
    
    if(p.empty()) return answer;
    
    answer = make_word(p);
    
    return answer;
}