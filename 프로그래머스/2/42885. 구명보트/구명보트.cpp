#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    
    deque <int> arr;
    
    for(auto i : people)
        arr.push_back(i);
    
    while(!arr.empty()){
        int temp = arr.front();
        for(int i = arr.size()-1; i>0; i--){
            if(temp + arr[i] <= limit){
                arr.erase(arr.begin() + i);
                break;
            }
            else{
                arr.pop_back();
                answer++;
            }
        }
        arr.pop_front();
        answer++;
    }
    
    //문제유형 : 그리디
    
    return answer;
}