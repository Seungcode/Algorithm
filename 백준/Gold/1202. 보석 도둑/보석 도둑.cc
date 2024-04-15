#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

//변수 설정
int N, K;
long long int answer = 0;
pair<int, int> j[300001];
int bag[300001] = {0, };
priority_queue<int> an;
int idx = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력받기
    cin>>N>>K;

    //보석 입력 받기
    for(int i = 0; i<N; i++){
        int M, V;
        cin>>M>>V;
        j[i] = {M, V};
    }

    //가방 무게 입력받기
    for(int i = 0; i<K; i++){
        cin>>bag[i];
    }

    //정렬
    sort(j, j+N);
    sort(bag, bag+K);

    //가방에 보석 담기 -> 무게가 가벼운 보석부터 담는다 -> 가격과 무게가 적은 것부터 차례로 정리 -> top에는 가장 비싼 주얼리가 들어옴
    for(int i = 0; i<K; i++){
        while(bag[i] >= j[idx].first && idx < N){
            an.push(j[idx].second);
            idx++;
        }
        if(!an.empty()) {
            answer+=an.top();
            an.pop();
        }
    }

    cout<<answer;

    //문제유형 : 그리디 + 정렬
}