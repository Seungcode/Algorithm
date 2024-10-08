#include <string>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

deque<pair<int, int>> arr;

int solution(vector<int> stones, int k) {
    int answer = INT_MAX;
    
    for(int i = 0; i<stones.size(); i++){
        while(!arr.empty() && arr.front().second <= i - k) arr.pop_front();
        
        while(!arr.empty() && arr.back().first <= stones[i]) arr.pop_back();
        
        arr.push_back({stones[i], i});
        if(i >= k - 1) answer = min(arr.front().first, answer);
    }
    
    if(answer == INT_MAX) answer = arr.front().first;
    
    return answer;
}