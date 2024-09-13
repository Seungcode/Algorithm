#include <string>
#include <vector>
#include <queue>
#include <map>
#include <iostream>

struct cars{
    int number;
    int time;
    
    bool operator <(const cars& others) const{
        if(number == others.number) return time > others.time;
        return number > others.number;
    }
};

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    map<int, int> arr;
    priority_queue<cars> q;
    
    //차 관련 정보 받기
    for(auto i : records){
        int time = stoi(i.substr(0, 2));
        int minute = stoi(i.substr(3, 2));
        int number = stoi(i.substr(6, 4));
        
        q.push({number, time*60 + minute});
    }
    
    //주차 된 시간 계산하기
    while(!q.empty()){
        int out_time;
        cars now = q.top();
        q.pop();
        
        if(!q.empty() && now.number == q.top().number){
            out_time = q.top().time;
            q.pop();
        }
        
        else{
            out_time = 23*60 + 59;
        }
        
        cout<<now.time<<" "<<out_time<<endl;
        
        arr[now.number] += out_time - now.time;
            
    }
    
    //요금 계산하기
    for(auto i : arr){
        if(i.second <= fees[0]){
            answer.push_back(fees[1]);   
        }
        else{
            int cost = fees[1];
            cost += (i.second - fees[0]) / fees[2] * fees[3];
            if((i.second - fees[0]) % fees[2] != 0) cost += fees[3];
            answer.push_back(cost);
        }
    }
    
    return answer;
}