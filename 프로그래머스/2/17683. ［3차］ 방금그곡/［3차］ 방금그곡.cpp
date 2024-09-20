#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

//우선순위 큐 사용을 위한 구조체
struct music{
    int time;
    string name;
    int index;
    
    bool operator<(const music& other) const{
        if(time == other.time) return index > other.index;
        return time < other.time;
    }
};

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    
    priority_queue<music> q;
    
    for(int i = 0; i<musicinfos.size(); i++){
        string temp = "";
        vector<string> temp_info;
        
        //문자열을 , 단위로 쪼갬
        for(auto j : musicinfos[i]){
            if(j == ',') {
                temp_info.push_back(temp);
                temp = "";
            }
            else temp += j;
        }
        
        temp_info.push_back(temp);
        temp = "";
        
        //시간 구하기
        int time = ((temp_info[1][0] - '0')*10 + (temp_info[1][1] - '0'))*60 + ((temp_info[1][3] - '0')*10 + (temp_info[1][4] - '0')) - (((temp_info[0][0] - '0')*10 + (temp_info[0][1] - '0'))*60 + ((temp_info[0][3] - '0')*10 + (temp_info[0][4] - '0')));
        
        //악보 만들기
        int temp_time = time;
        for(int j = 0; j<time; j++){
            temp += temp_info[3][j%temp_info[3].length()];
            
            //#이 붙어있을 경우
            if(temp_info[3][(j + 1)%temp_info[3].length()] == '#'){
                temp += temp_info[3][(j + 1)%temp_info[3].length()];
                j++;
                time ++;
            }
            
            //점검해 볼 길이가 될 때
            if(temp.length() >= m.length()){
                //길이만큼 자른 후 같은지 확인
                if(m == temp.substr(temp.length() - m.length(), m.length())){
                    q.push({temp_time, temp_info[2], i});
                    break;
                }
            }
        }
    }
    
    if(q.empty()) answer = "(None)";
    else answer = q.top().name;
    
    return answer;
}