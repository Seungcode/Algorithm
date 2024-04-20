#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

//변수 설정
int N, K;
vector<int> arr;
int answer = INT_MAX;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력받기
    cin>>N>>K;

    for(int i = 0; i<N; i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }

    //포인터 설정
    int start = 0;
    int end = 0;
    int temp = arr[0];

    //포인터를 이동시켜가며 최소 길이 찾기
    while(end < N){
        if(temp >= K && (answer > end - start)){
            answer = end - start;
            temp -= arr[start];
            start++;
        }
        else if(temp > K){
            temp -= arr[start];
            start++;
        }
        else{
            end++;
            temp += arr[end];
        }
    }

    //값이 없을 경우
    if(answer == INT_MAX){
        cout<<0;
        return 0 ;
    }
    //값이 있을 경우
    else{
        cout<<answer + 1;
        return 0;
    }

    //문제유형 : 투포인터
}