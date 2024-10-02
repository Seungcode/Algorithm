#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

vector<int> emozi;
vector<int> buy[5];
map<int, int> e_plus;
map<int, int> cost;
priority_queue<pair<int, int>> q;

void make_sale(int now, int sales){
    //끝까지 확인이 끝났다면
    if(now == emozi.size()) {
        int cnt = 0;
        int count = 0;
        
        for(auto i : cost){
            if(i.second >= e_plus[i.first]) cnt++;
            else count += i.second;
        }
        
        q.push({cnt, count});
        return;
    }
    
    int sale_cost = emozi[now] - (int)((double)emozi[now]*(0.1*sales));
    
    //판매 금액 계산
    for(int i = 0; i<=sales; i++){
        for(auto j : buy[i]){
            cost[j] += sale_cost;
        }
    }
    
    for(int i = 1; i<=4; i++) make_sale(now + 1, i);
    
    //판매 금액 초기화
    for(int i = 0; i<=sales; i++){
        for(auto j : buy[i]){
            cost[j] -= sale_cost;
        }
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    
    emozi = emoticons;
    
    for(int i = 0; i<users.size(); i++){
        if(users[i][0] <= 40){
            if(users[i][0] % 10 == 0) buy[users[i][0]/10].push_back(i);
            else buy[users[i][0] / 10 + 1].push_back(i);
            e_plus[i] = users[i][1];
        }
    }
    
    for(int i = 1; i<=4; i++) make_sale(0, i);
    
    answer.push_back(q.top().first);
    answer.push_back(q.top().second);
    
    return answer;
}