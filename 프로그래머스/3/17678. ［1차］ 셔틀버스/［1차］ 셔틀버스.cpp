#include <string>
#include <vector>
#include <queue>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    
    int now = 9*60;
    n--;
    int cnt = 0;
    
    priority_queue<int, vector<int>, greater<>> q;
    
    for(auto i : timetable){
        q.push(stoi(i.substr(0, 2))*60 + stoi(i.substr(3, 2)));
    }
    
    int last;
    
    while(!q.empty()){
        last = q.top();
        while(last > now){
            if(n==0) break;
            now += t;
            cnt = 0;
            n--;
        }
        
        if(n==0 && last > now) break;
        
        q.pop();
        
        cnt ++;
        if(n == 0 && cnt == m) break;
        if(cnt >= m){
            cnt = 0;
            n--;
            now += t;
        }
    }
    
    if(cnt < m) last = now + (n*t);
    else last--;
    
    if(last/60 < 10) answer += '0';
    else if(last/60 == 0) answer += '0';
    answer += to_string(last/60);
    
    answer += ':';
    
    if(last%60 < 10) answer += '0';
    else if(last%60 == 0) answer += '0';
    answer += to_string(last%60);
    
    return answer;
}