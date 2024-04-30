#include <iostream>
#include <queue>
#include <map>
using namespace std;

int solution(int n)
{
    int ans = 0;
    
    while(n>=1){
        if(n%2==0)
            n/=2;
        else{
            n--;
            ans++;
        }
    }

    //문제유형 : 구현
    
    return ans;
}