#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    
    //우선순위 큐를 사용하여 정렬
    priority_queue <int, vector<int>, greater<int>> arr;
    
    //하나씩 넣으면서 가장 작은 점수 answer에 넣어주기
    for(auto i : score){
        arr.push(i);
        if(arr.size() > k)
            arr.pop();
        answer.push_back(arr.top());
    }
    
    //문제유형 : 구현 (우선순위 큐)
    
    return answer;
}