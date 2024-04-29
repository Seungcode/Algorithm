#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    //초기 배열값 세팅
    answer.resize(prices.size());
    for(int i = 0; i<prices.size(); i++){
        answer[i] = prices.size() -1 -i;
    }
    
    priority_queue <pair<int, int>> q;
    
    //하나씩 돌면서 확인하기
    for(int i = 0; i<prices.size(); i++){
        q.push({prices[i], i});
        while(q.top().first > prices[i]){
            answer[q.top().second] = i - q.top().second;
            q.pop();
        }
    }
    
    //문제유형 : 스택 / 큐
    return answer;
}