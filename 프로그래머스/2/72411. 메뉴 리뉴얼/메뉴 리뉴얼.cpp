#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

//문자열 반복 수 저장
map<string, int> arr;
//저장할 길이의 문자열인지 확인용
map<int, int> len;
//최대 반복 수 저장
int course_num[11] = {0, };

//문자열 생성
void pemu(string now, string a, int cnt){
    //마지막까지 왔을 때 -> 저장할 길이면 map에 체크
    if(cnt == now.length() - 1){
        if(len[a.length()]!=0) arr[a] ++;
        return;
    }
    
    //다음 문자열 생성
    pemu(now, a + now[cnt + 1], cnt + 1);
    pemu(now, a, cnt + 1);
} 

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    //횟수가 작은 순으로 정렬되는 우선순위큐
    priority_queue<pair<int, string>> q;
    
    //문자열 생성
    for(auto i : course) len[i] ++;
    for(auto i : orders) {
        //최종적으로 오름차순 정렬을 한 코스를 출력해야함 -> 오름차순으로 정렬
        sort(i.begin(), i.end());
        pemu(i, "", -1);
    }
    
    //2번 이상 반복되는 경우 -> 우선순위큐에 저장
    for(auto i : arr){
        if(i.second >= 2) q.push({i.second, i.first});
    }
    
    //큐가 빌 때까지 반복
    while(!q.empty()){
        //가장 크거나 가장 큰 것과 같을 경우 -> 배열에 값 넣어주기
        if(course_num[q.top().second.length()] == 0 || 
           course_num[q.top().second.length()] == q.top().first)
        {
            course_num[q.top().second.length()] = q.top().first;
            answer.push_back(q.top().second);
        }
        
        q.pop();
    }
    
    //정렬
    sort(answer.begin(), answer.end());
    
    return answer;
}