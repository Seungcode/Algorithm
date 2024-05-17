#include <string>
#include <vector>

using namespace std;

bool IS_Prime(long long int j){
    for(long long int i = 2; i*i<=j; i++){
        if(j%i==0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    vector<int> arr;
    string a = "";
    
    //진수 변환
    while(n > 0){
        a += to_string(n%k);
        n = n/k;
    }
    
    //숫자화하기
    long long int temp = 0;
    for(int i = a.length()-1; i>=0; i--){
        if(a[i] == '0') {
            if(IS_Prime(temp) && temp > 1) answer++;
            temp = 0;
        }
        else temp = temp*10 + (a[i]-'0');
    }
    if(IS_Prime(temp) && temp > 1) answer++;
    
    return answer;
    
    //문제유형 : 수학
}