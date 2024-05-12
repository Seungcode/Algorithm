#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool comp(vector<int> a, vector<int> b){
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> arr;
    map<int, int> cnt;
    
    for(int i = 1; i<s.length()-1; i++)
    {
        if(s[i] == '{'){
            vector<int> temp;
            int now = 0;
            for(int j = i+1; j<s.length()-1; j++){
                if(s[j] == '}') {
                    temp.push_back(now);
                    break;
                }
                if(s[j] == ',') {
                    temp.push_back(now);
                    now = 0;
                }
                else now = now*10 + (s[j] - '0');
                i++;
            }
            arr.push_back(temp);
        }
    }
    
    sort(arr.begin(), arr.end(), comp);
    
    for(auto i : arr){
        for(auto j : i){
            if(cnt[j] == 0) answer.push_back(j);
            cnt[j]++;
        }
    }
    
    //문제유형 : 구현 + 정렬
    
    return answer;
}