#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;    
    
    //완성 배열 만들기
    for(long long int i = left; i<=right; i++){
       answer.push_back(max(i%n, i/n) + 1);
    }
    
    //문제유형 : 구현
    
    return answer;
}