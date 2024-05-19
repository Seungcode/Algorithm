#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> arr;
    for(int i = 0; i<msg.length(); i++){
        string a = "";
        a += msg[i];
        arr[a] = (msg[i] - 'A') + 1;
    }
    
    int cnt = 0;
    string now = "";
    for(int i = 0; i<msg.length(); i++){
        now = "";
        for(int j = i; j<msg.length(); j++){
            now+=msg[j];
            if(arr[now]!=0) {
                i++;
                continue;
            }
            else {
                arr[now] = 27+cnt;
                cnt++;
                i--;
                now.pop_back();
                answer.push_back(arr[now]);
                break;
            }
        }
    }
    answer.push_back(arr[now]);
    return answer;
    
    //문제유형 : 구현
}