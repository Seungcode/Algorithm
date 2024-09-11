#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//소수 찾기
bool find_prime(long long n){
    if(n<2) return false;
    for(long long i = 2; i*i<=n; i++)
        if(n%i == 0) return false;
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    
    //n진수로 변환
    string a = "";
    while(n!=0){
        a += to_string(n%k);
        n = n/k;
    }
    
    reverse(a.begin(), a.end());
    
    string temp = "";
    
    for(auto i : a){
        //0이오고 temp에 수가 있다면
        if(i=='0' && temp.length() > 0){
            if(find_prime(stol(temp))) answer++;
            temp = "";
        }
        //연속으로 0이 온다면
        else if(i=='0') continue;
        //수가 온다면
        else temp += i;
    }
    
    //마지막에 0이 아닌 수로 끝났다면
    if(temp.length() > 0 && find_prime(stol(temp))) answer++;
    
    return answer;
}