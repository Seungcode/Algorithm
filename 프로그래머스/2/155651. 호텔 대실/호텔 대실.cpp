#include <string>
#include <sstream>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    //시간을 담아주기 위한 배열
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<>> time;
    
    //방을 맡아줄 배열
    vector<int> arr;
    
    //시간 담아주기 -> 대실이 빨리 시작하는 대로
    for(auto i : book_time){
        int start = stoi(i[0].substr(0, 2)) * 60 + stoi(i[0].substr(3, 2));
        int end = stoi(i[1].substr(0, 2)) * 60 + stoi(i[1].substr(3, 2)) + 10;
        time.push({start, end});
    }
    
    //방 개수 구하기
    while(!time.empty()){
        int start = time.top().first;
        int end = time.top().second;
        time.pop();
        int flag = 1;
        
        //현재 들어갈 수 있는 방의 여부 확인하기
        for(int j = 0; j<arr.size(); j++){
            if(arr[j] <= start){
                arr[j] = end;
                flag = 0;
                break;
            }
        }
        
        //플래그가 0이면 다른 방 사용이 가능 -> 1이면 방 새로 추가
        if(flag == 1) arr.push_back(end);
    }
    
    //방 개수 == 배열의 크기
    answer = arr.size();
    return answer;
    
    //문제유형 : 자료구조
}