#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, int> arr;

//map 초기화 -> 기본 알파벳 넣어두기
void initArr(){
    string now = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(int i = 0; i<26; i++){
        arr[to_string(now[i])] = i+1;
    }
}

vector<int> solution(string msg) {
    vector<int> answer;
    
    initArr();
    
    //인덱스 값
    int cnt = 27;
    
    for(int i = 0; i<msg.length();){
        string temp = to_string(msg[i]);
        
        //존재하는 가장 긴 문자열 + 1까지
        while(arr[temp] != 0 && i<msg.length()){
            i++;
            temp += msg[i];
        }
        
        //새로 저장하고
        arr[temp] = cnt;
        cnt++;
        
        //맨 뒤에꺼 빼고 배열에 값 넣어주기
        temp.pop_back();
        answer.push_back(arr[temp]);
    }
    
    return answer;
}