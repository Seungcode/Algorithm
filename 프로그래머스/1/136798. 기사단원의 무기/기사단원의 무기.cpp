#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    
    //약수의 갯수를 저장하기 위한 변수
    map <int, int> arr;
    
    //하나씩 해당 수를 약수로 가지는 것마다 +1씩해서 약수의 갯수 구하기
    for(int i = 1; i<=number; i++){
        for(int j = i; j<=number;){
            arr[j]++;
            j+=i;
        }
    }
    
    //답 구하기
    for(int i = 1; i<=number; i++)
        arr[i] <= limit ? answer+=arr[i] : answer+=power;
    
    //문제유형 : 구현 (수학)
    
    return answer;
}