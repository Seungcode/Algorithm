#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    // 초기값 -1로 설정
    vector<int> answer(numbers.size(), -1); 
    
    stack<int> s;

    for (int i = 0; i < numbers.size(); ++i) {
        while (!s.empty() && numbers[s.top()] < numbers[i]) {
            // 스택의 top 요소의 결과를 현재 값으로 갱신
            answer[s.top()] = numbers[i]; 
            
            // 해당 요소는 더 이상 필요 없으므로 제거
            s.pop(); 
        }
        
        // 인덱스를 스택에 추가
        s.push(i); 
    }
    
    //문제유형 : 자료구조

    return answer;
}
