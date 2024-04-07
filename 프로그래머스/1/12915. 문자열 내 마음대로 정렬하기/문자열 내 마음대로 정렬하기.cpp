#include <string>
#include <vector>
#include <queue>

using namespace std;

//우선순위를 결정할 구조체
struct cmp{
    bool operator() (pair<pair<char,string>, int> a, pair<pair<char,string>, int> b){
        if(a.first.first == b.first.first)
            return a.first.second > b.first.second;
        return a.first.first > b.first.first;
    }
};

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    
    //우선순위큐 정의
    priority_queue <pair<pair<char,string>, int>, vector<pair<pair<char,string>, int>>, cmp> arr;
    
    //인덱스
    int index = 0;
    
    //큐에 값 넣어주기
    for(auto i : strings){
        arr.push({{i[n], i}, index});
        index++;
    }
    
    //해당 값부터 정답칸에 넣어주기
    while(!arr.empty()){
        answer.push_back(strings[arr.top().second]);
        arr.pop();
    }
    
    //문제유형 : 정렬 + 문자열
    return answer;
}