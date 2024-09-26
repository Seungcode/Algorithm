#include <string>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
using namespace std;

vector<vector<string>> arr;
map<string, int> visited;

struct key_list{
    string key;
    
    bool operator<(const key_list& other) const{
        if(other.key.length() == key.length()) return key > other.key;
        return other.key.length() < key.length();
    }
};

priority_queue<key_list> q;

bool check_visited(string included, string a, int now){
    if(visited[a] > 0) return false;
    
    if(now >= included.length() - 1) return true;
    
    if(!check_visited(included, a, now + 1) ||
       !check_visited(included, a + included[now+1], now+1)) 
        return false;
    
    return true;
}

void candinate(vector<int> included, int now){
    map<string, int> key;
    //배열을 다 돌았으면 리턴
    if(now == arr[0].size()) return;
    
    //후보키가 가능한지 확인하기
    for(int i = 0; i<arr.size(); i++){
        string temp = "";
        
        //문자열 만들어 후보키 가능한지 확인하기
        for(auto j : included) temp += arr[i][j];
        
        //불가능 할 경우 다른 조합 확인해보기
        if(key[temp] != 0){
            candinate(included, now+1);
            included.push_back(now+1);
            candinate(included, now+1);
            return;
        }
        
        key[temp] ++;
    }
    
    string candinate_key = "";
    for(auto i : included){
        candinate_key += i + '0';
    }
    
    //가능하다면 수를 늘리고 다른 조합은 살펴보지 않음 -> 최소성 위반
    q.push({candinate_key});
    return;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    
    arr = relation;
    vector<int> included;
    
    for(int i = 0; i<relation[0].size(); i++){
        included.push_back(i);
        candinate(included, i);
        included.pop_back();
    }
    
    //최소성 확인
    while(!q.empty()){
        string now = q.top().key;
        q.pop();
        
        if(!check_visited(now, "", 0) ||
          !check_visited(now, to_string(now[0] - '0'), 0)) continue;
        
        answer ++;
        visited[now] ++;
    }
    return answer;
}