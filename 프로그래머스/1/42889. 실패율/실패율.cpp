#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

//정렬을 위한 비교함수
bool com(pair<int, double> a, pair<int, double> b){
    if(a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    //스테이지에 있는 사람 수
    map <int, int> arr;
    
    //실패율을 담기 위함
    vector<pair<int, double>> fail;
    
    //사람 수
    int person = 0;
    
    //스테이지별 사람 수 저장
    for(auto i : stages){
        if(i==N+1)
            person++;
        arr[i] ++;
    }
    
    //실패율 저장
    for(int i = N; i>=1; i--){
        person += arr[i];
        if(person == 0)
            fail.push_back({i, 0});
        else
            fail.push_back({i, (double)arr[i]/person});
    }
    
    //기준에 맞춰 정렬
    sort(fail.begin(), fail.end(), com);
    
    //배열에 맞는 값 넣어주기
    for(auto i : fail)
        answer.push_back(i.first);
    
    //문제유형 : 구현
    return answer;
}