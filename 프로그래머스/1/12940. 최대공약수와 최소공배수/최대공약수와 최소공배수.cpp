#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    
    //최대공약수와 최소공배수
    int max_same = 1;
    int min_same = 1;
    
    //수행
    for(int i = 2; i<=max(n, m); i++){
        //둘의 공약수일 경우
        if(n%i==0 && m%i==0){
            min_same *=i;
            max_same *= i;
            n = n/i;
            m = m/i;
            i--;
        }
        
        //하나만의 약수일 경우
        else if(n%i==0 || m%i==0){
            n%i==0 ? n=n/i : m=m/i;
            max_same*=i;
            i--;
        }
    }
    
    //배열에 넣어주기
    answer.push_back(min_same);
    answer.push_back(max_same);
    
    //문제유형 : 수학
    return answer;
}