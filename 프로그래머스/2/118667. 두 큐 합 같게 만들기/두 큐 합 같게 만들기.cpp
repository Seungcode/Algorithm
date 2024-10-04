#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    
    //pop_front를 사용하기 위해 deque로 이전 & 합 구하기
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
        //같을 경우
        if(one == two) break;
        //최대 수보다 클 경우 -> 큐에 왔다 갔다하는 최대 경우보다 크면 -1
        else if(answer > 2*queue1.size() + 1) return -1;
        //1번큐의 값이 더 클 경우
        else if(one < two){
            arr1.push_back(arr2.front());
            two -= arr2.front();
            one += arr2.front();
            arr2.pop_front();
        }
        //2번 큐의 값이 더 클경우
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