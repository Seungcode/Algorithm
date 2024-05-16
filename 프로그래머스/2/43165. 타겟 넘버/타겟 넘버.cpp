#include <string>
#include <vector>
#include <iostream>

using namespace std;
int answer = 0;
vector<int> arr;

void bfs(int now, int cnt, int target){
    if(cnt == target && now == arr.size()-1) answer++;
    if(now == arr.size()-1) return;
    bfs(now+1, cnt+arr[now+1], target);
    bfs(now+1, cnt-arr[now+1], target);
}


int solution(vector<int> numbers, int target) {
    arr = numbers;
    bfs(-1, 0, target);
    return answer;
}