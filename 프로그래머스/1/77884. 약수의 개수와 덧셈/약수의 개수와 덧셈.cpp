#include <string>
#include <map>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    
    //약수의 갯수를 저장하기 위한 배열
    map <int, int> arr;
    
    //right까지 약수의 갯수 저장
    for(int i = 1; i<=right; i++){
        for(int j = i; j<=right; j+=i)
            arr[j]++;
    }
    
    //짝수면 더하고 홀수면 빼기
    for(int i = left; i<=right; i++){
        arr[i]%2==0 ? answer+=i : answer-=i;
    }
    
    //문제유형 : 구현(수학)
    
    return answer;
}