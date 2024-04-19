#include <iostream>
#include <vector>

using namespace std;

//변수 설정
int N;
vector<int> prime;
bool visited[4000001] = {false, };
int answer = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력받기
    cin>>N;

    
    //소수 먼저 찾기 -> 소수는 하나의 배열에 넣어준다.
    for(int i = 2; i<=4000000; i++){
        if(!visited[i]){
            visited[i] = true;
            prime.push_back(i);
            for(int j = i+i; j<=4000000; j+=i)
                visited[j] = true;
        }
    }

    //연속된 소수로 해당 값을 만들 수 있는지 확인
    for(int i = 0; i<prime.size(); i++){
        int temp = 0 ;
        for(int j = i; j<prime.size(); j++){
            temp += prime[j];
            if(temp == N){
                answer++;
                break;
            }
            else if(temp > N) break;
        }
    }

    cout<<answer;
    
    //문제유형 : 수학 (정수론)
}