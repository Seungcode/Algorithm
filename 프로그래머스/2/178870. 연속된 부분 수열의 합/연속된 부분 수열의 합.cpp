#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(1000001);
    
    int start = 0;
    int end = 0;
    int sum = sequence[0];
    
    //연속 부분 수열의 합 구하기
    while(end<sequence.size()){
        if(sum == k){
            if(answer[1]-answer[0] > end-start){
                answer[0] = start;
                answer[1] = end;
            }
            end++;
            sum += sequence[end];
        }
        if(sum > k){
            sum -= sequence[start];
            start++;
        }
        else if(sum < k){
            end ++;
            sum += sequence[end];
        }
    }
    
    //문제유형 : 투포인터
    return answer;
}