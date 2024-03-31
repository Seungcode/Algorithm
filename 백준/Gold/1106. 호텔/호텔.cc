#include <iostream>
#include <vector>

using namespace std;

//원하는 값과 도시의 수를 담을 변수
int C, N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력받기
    cin>>C>>N;

    //결과를 담을 배열
    int result[100001] = {0, };
    vector<pair<int, int>> arr;

    //주어지는 금액과 고객 수 저장
    for(int i = 0; i<N; i++){
        int M, P;
        cin>>M>>P;
        result[M] = max(result[M], P);
        arr.push_back({M, P});
    }

    //금액대별로 만들 수 있는 최대 인원수 저장
    for(int i = 1; i<100001; i++){
        for(int j = 0; j<N; j++) {
            if(i-arr[j].first>=0) {
                result[i] = max(result[i], result[arr[j].first] + result[i - arr[j].first]);
            }
            if(result[i] >= C) {
                cout << i;
                return 0;
            }
        }
    }

    //문제유형 : 다이나믹 프로그래밍
}