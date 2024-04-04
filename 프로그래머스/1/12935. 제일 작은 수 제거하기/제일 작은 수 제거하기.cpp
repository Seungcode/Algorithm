#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    //최소값 구하기
    int min_arr = arr[0];
    for(auto i : arr)
        min_arr = min(min_arr, i);
    
    //최소값 빼고 넣기
    for(auto i : arr)
        if(i!=min_arr) answer.push_back(i);
    
    //배열이 비어있을 경우
    if(answer.size()==0)
        answer.push_back(-1);
    
    //문제유형 : 정렬
    return answer;
}