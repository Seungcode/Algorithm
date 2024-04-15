#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    
    //현재 인덱스와 나오고 있는 상자의 번호
    int index = 0;
    int cnt = 1;
    
    //임시보관용 스택 (후입선출)
    stack <int> arr;
    
    //실행
    while(cnt<=order.size()){
        //만일 지금 나오는 상자가 필요하다면
        if(cnt == order[index]) {
            answer ++;
            index++;
        }
        
        //아니라면
        else arr.push(cnt);
        
        //보조 컨테이너에서 꺼내오기
        while(true){
            if(arr.empty()) break;
            if(arr.top() != order[index]) break;
            else{
                answer++;
                index++;
                arr.pop();
            }
        }
        cnt++;
    }
    
    //문제유형 : 자료구조
    return answer;
}