#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    
    //x -> int but 최대값은 10000000*1000 -> longlong형으로 변경
    long long temp = x;
    
    //수행
    for(int i = 0; i < n; i++){
        answer.push_back(temp);
        temp += x;
    }
    
    //문제유형 : 구현
    return answer;
}