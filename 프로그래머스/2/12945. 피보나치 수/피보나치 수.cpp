#include <string>
#include <vector>

using namespace std;

int dp[100001] = {0, };

//재귀 함수
int fibo(int i){
    if(i==0)
        return 0;
    if(i==1)
        return 1;
    if(dp[i] != 0)
        return dp[i];
    return dp[i] = (fibo(i-1) + fibo(i-2))%1234567;
}

int solution(int n) {
    int answer = 0;
    answer = fibo(n);
    
    //문제유형 : dp
    
    return answer;
}