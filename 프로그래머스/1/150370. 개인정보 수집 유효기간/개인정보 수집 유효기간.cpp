#include <string>
#include <vector>
#include <map>
using namespace std;

map<char, int> term;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    //개인정보 보호 기간 정리
    for(auto i : terms) 
        term[i[0]] = stoi(i.substr(2, i.length() - 2));
    
    //오늘 일자 정리
    int n_year = stoi(today.substr(0, 4));
    int n_month = stoi(today.substr(5, 2));
    int n_day = stoi(today.substr(8, 2));

    for(int i = 0; i<privacies.size(); i++){
        //개인정보 보호 기간 확인
        int year = stoi(privacies[i].substr(0, 4));
        int month = stoi(privacies[i].substr(5, 2)) + term[privacies[i].back()];
        int day = stoi(privacies[i].substr(8, 2));
        
        //12월을 지날 경우 -> 년도 올려주기
        if(month > 12){
            year += month/12;
            month = month%12;
            if(month == 0) {
                year --;
                month = 12;
            }
        }
        
        //유효기간이 지났는지 확인
        if(year > n_year) continue;
        if(year < n_year) {
            answer.push_back(i+1);
            continue;
        }
        
        if(month > n_month) continue;
        if(month < n_month) {
            answer.push_back(i+1);
            continue;
        }
        
        if(day > n_day) continue;
        if(day <= n_day) {
            answer.push_back(i+1);
            continue;
        }
    }
    
    return answer;
}