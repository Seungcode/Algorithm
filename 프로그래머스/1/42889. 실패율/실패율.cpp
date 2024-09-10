#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

//vector 정렬을 위한 함수
bool comp(pair<double, int> a, pair<double, int> b){
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    //실패율과 각 스테이지에 머무는 사람을 저장하기 위한 배열
    vector<pair<double, int>> fail; 
    map<int, double> now;
    
    //사람 수 초기화
    double people = stages.size();
    
    //스테이지당 사람 수 세기 -> N+1은 굳이 고려 X
    for(auto i : stages) now[i]++;
    
    //1스테이지부터 실패율을 구한 후 현재 스테이지에 머무는 사람을 빼줌 -> 다음 스테이지로 간 사람 수
    for(int i = 1; i<=N; i++){
        if(people == 0) fail.push_back({0, i});
        else fail.push_back({now[i]/people, i});
        people -= now[i];
    }
    
    //정렬
    sort(fail.begin(), fail.end(), comp);
    
    //정답 배열에 스테이지 넣어주기
    for(auto i : fail) {
        answer.push_back(i.second);
    }
    
    return answer;
}