#include <string>
#include <vector>
#include <map>

using namespace std;

//최종 이름을 저장할 배열
map<string, string> arr;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    //명령어 저장
    vector<string> user;
    
    for(auto i : record){
        string temp = "";
        
        //명령어 + 유저 아이디 + 닉네임 저장
        for(auto j : i){
            if(j == ' '){
                user.push_back(temp);
                temp = "";
            }
            else temp += j;
        }
        user.push_back(temp);
        
        //닉네임이 바뀔 경우와 아닐 경우를 나누어 이름 저장
        if(user[user.size()-2] == "Leave") continue;
        else {
            arr[user[user.size() - 2]] = user.back();
            user.pop_back();
        }
    }
    
    //명령어에 따른 출력문 저장
    for(int i = 0; i<user.size(); i+=2){
        if(user[i] == "Enter") answer.push_back(arr[user[i+1]] + "님이 들어왔습니다.");
        else if(user[i] == "Leave") answer.push_back(arr[user[i+1]] + "님이 나갔습니다.");
    }
    
    return answer;
}