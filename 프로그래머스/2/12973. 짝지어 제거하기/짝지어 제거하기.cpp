#include <iostream>
#include<string>
#include <queue>
using namespace std;

int solution(string s)
{
    int answer = -1;

    deque <char> q;
    
    for(int i = 0; i<s.length(); i++){
        //큐에 값 넣어주기
        q.push_back(s[i]);

        //마지막 두 칸 비교
        while(q.size()>=2){
            if(q[q.size()-1] == q[q.size()-2]){
                q.pop_back();
                q.pop_back();
            }
            else
                break;
        }
        
    }
    
    //정답 결정
    answer = q.empty() ? 1: 0;

    //문제유형 : 자료구조
    return answer;
}