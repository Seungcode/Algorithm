#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    //숫자 넣어줄 벡터
    vector<int> arr;
    
    //각 자리수 넣어주기
    while(n>0){
        arr.push_back(n%10);
        n = n/10;
    }
    
    //정렬 -> 큰 숫자 순서로
    sort(arr.begin(), arr.end(), greater());
    
    //결과 산출
    for(auto i : arr)
        answer = answer*10 + i;
    
    //문제유형 : 구현
    return answer;
}