#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    vector<int> arr;
    
    //이진수 값 구하기
    while(n>0){
        arr.push_back(n%2);
        n = n/2;
    }
    arr.push_back(0);
    
    //다음 배열 찾기 -> 1의 수는 같으면서 바로 다음 배열
    next_permutation(arr.rbegin(), arr.rend());
    
    //값 계산
    int cnt = 1;
    for(auto i : arr){
        if(i == 1) answer += cnt;
        cnt*=2;
    }
    
    return answer;
    
    //문제유형 : 순열
}