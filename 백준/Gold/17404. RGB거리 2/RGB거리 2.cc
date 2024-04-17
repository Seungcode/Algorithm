#include <iostream>
#include <limits.h>

using namespace std;

//변수 설정
int N;
int arr[1001][3] = {0, };
int sum[1001][3][3] = {0, };
int answer = INT_MAX;


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력받기
    cin>>N;

    //수 입력받고 인덱스 저장하기
    for(int i = 0; i<N; i++){
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    }


    //첫칸 저장하기 -> 마지막 답 정할 때 쓸 예정
    sum[1][0][1] = arr[1][0] + arr[0][1];
    sum[1][0][2] = arr[1][0] + arr[0][2];

    sum[1][1][0] = arr[1][1] + arr[0][0];
    sum[1][1][2] = arr[1][1] + arr[0][2];

    sum[1][2][0] = arr[1][2] + arr[0][0];
    sum[1][2][1] = arr[1][2] + arr[0][1];

    
    //dp 수행
    for(int i = 2; i<N; i++){
        //2에서는 1이 0인 경우가 생길 수 있음 -> 그 경우만 예외처리
        sum[i][0][0] = min(sum[i-1][1][0], sum[i-1][2][0])  + arr[i][0];
        sum[i][0][1] = min(sum[i-1][1][1], sum[i-1][2][1]) == 0 ? sum[i-1][2][1] + arr[i][0] : min(sum[i-1][1][1], sum[i-1][2][1]) + arr[i][0];
        sum[i][0][2] = min(sum[i-1][1][2], sum[i-1][2][2]) == 0 ? sum[i-1][1][2] + arr[i][0] : min(sum[i-1][1][2], sum[i-1][2][2]) + arr[i][0];

        sum[i][1][0] = min(sum[i-1][0][0], sum[i-1][2][0]) == 0 ? sum[i-1][2][0] + arr[i][1] : min(sum[i-1][0][0], sum[i-1][2][0]) + arr[i][1];
        sum[i][1][1] = min(sum[i-1][0][1], sum[i-1][2][1]) + arr[i][1];
        sum[i][1][2] = min(sum[i-1][0][2], sum[i-1][2][2]) == 0 ? sum[i-1][0][2] + arr[i][1] : min(sum[i-1][0][2], sum[i-1][2][2]) + arr[i][1];

        sum[i][2][0] = min(sum[i-1][0][0], sum[i-1][1][0]) == 0 ? sum[i-1][1][0] + arr[i][2] : min(sum[i-1][0][0], sum[i-1][1][0]) + arr[i][2];
        sum[i][2][1] = min(sum[i-1][0][1], sum[i-1][1][1]) == 0 ? sum[i-1][0][1] + arr[i][2] :  min(sum[i-1][0][1], sum[i-1][1][1]) + arr[i][2];
        sum[i][2][2] = min(sum[i-1][0][2], sum[i-1][1][2]) + arr[i][2];
    }

    //i랑 j가 같을 경우 -> 1번과 최종 N-1번이 같은 경우 -> 제외
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            if(i==j) continue;
            answer = min(answer, sum[N-1][i][j]);
        }
    }

    //출력
    cout<<answer;

    //문제유형 : dp
}