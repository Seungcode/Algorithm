#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    //현재 귤의 갯수
    int now = 0;
    
    //각 크기별 귤의 갯수
    map<int, int> cnt;
    priority_queue <int> arr;
    
    //크기별로 묶기
    for(auto i : tangerine)
        cnt[i] ++;
    
    //더 많은게 위로 오도록 정렬한 큐에 넣어주기
    for(auto i : cnt)
        arr.push(i.second);
    
    //귤의 갯수가 충분할 때 까지 연산
    while(now<k){
        answer++;
        now += arr.top();
        arr.pop();
    }
    
    //문제유형 : 정렬
    
    return answer;
}