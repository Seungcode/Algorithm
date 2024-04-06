#include <string>
#include <vector>

using namespace std;

int arr[1000001] = {0, };

int solution(int n) {
    int answer = 0;
    
    //소수 체크하기
    for(int i = 2; i<=n; i++){
        if(arr[i] == 0){
            for(int j = i*2; j<=n; j+=i)
                arr[j]++;
        }
    }
    
    //답 구하기
    for(int i = 2; i<=n; i++)
        if(arr[i] == 0) answer++;
    
    //문제유형 : 수학
    return answer;
}