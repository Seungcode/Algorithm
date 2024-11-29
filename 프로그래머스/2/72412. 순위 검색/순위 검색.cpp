#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

map<string, vector<int>> arr;

void collect(int now, int score, vector<string> prefer, string temp){
    if(now == 4) {
        arr[temp].push_back(score);
        return;
    }
    collect(now+1, score, prefer, temp + prefer[now]);
    collect(now+1, score, prefer, temp + "-");
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    for(auto i : info){
        vector<string> temp;
        string tem = "";
        for(auto j : i){
            if(j == ' '){
                temp.push_back(tem);
                tem = "";
            }
            else tem += j;
        }
        
        int score = stoi(tem);
        collect(0, score, temp, "");
    }
    
    for(auto i : arr)
        sort(arr[i.first].begin(), arr[i.first].end());
    
    for(auto i : query){
        string temp = "";
        string tem = "";
        for(auto j : i){
            if(j == ' '){
                if(tem == "and"){
                    tem = "";
                }
                else{
                    temp += tem;
                    tem = "";
                }
            }
            else tem += j;
        }
        auto it = lower_bound(arr[temp].begin(), arr[temp].end(), stoi(tem));
        answer.push_back(arr[temp].size() - (it - arr[temp].begin()));
    }
    return answer;
}