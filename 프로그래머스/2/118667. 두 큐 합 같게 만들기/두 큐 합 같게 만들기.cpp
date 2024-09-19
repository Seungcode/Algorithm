#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    
    long one = 0, two = 0;
    deque<int> arr1;
    deque<int> arr2;
    
    for(int i = 0; i<queue1.size(); i++){
        one += queue1[i];
        two += queue2[i];
        arr1.push_back(queue1[i]);
        arr2.push_back(queue2[i]);
    }
    
    while(true){
        if(one == two) break;
        else if(answer > 4*queue1.size()) return -1;
        else if(one < two){
            arr1.push_back(arr2.front());
            two -= arr2.front();
            one += arr2.front();
            arr2.pop_front();
        }
        else {
            arr2.push_back(arr1.front());
            two += arr1.front();
            one -= arr1.front();
            arr1.pop_front();
        }
        answer++;
    }
    return answer;
}