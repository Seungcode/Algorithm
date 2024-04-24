#include <map>
#include <iostream>

using namespace std;

//변수 선언
int N, A_I, B_I;
map<long long int, int> s;
int A[1001];
int B[1001];
long long int answer = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력받기
    cin>>N;

    cin>>A_I;
    for(int i = 0; i<A_I; i++)
        cin>>A[i];

    cin>>B_I;
    for(int i = 0; i<B_I; i++)
        cin>>B[i];


    //map에 값 저장
    long long int temp;

    for(int j = 0; j<A_I; j++){
        temp = 0;
        for(int i = j; i>=0; i--){
            temp+=A[i];
            s[temp]++;
        }
    }

    //값 있는지 확인하기 -> 있으면 answer에 넣어주기

    for(int j = 0; j<B_I; j++){
        temp = 0;
        for(int i = j; i>=0; i--){
            temp += B[i];
            answer += s[N-temp];
        }
    }

    cout<<answer;
    //문제유형 : 투포인터 + 해시
}