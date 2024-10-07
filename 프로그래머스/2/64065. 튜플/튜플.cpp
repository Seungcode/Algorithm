#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

//현재 수가 배열에 추가되었는지 확인하기 위한 map
map<int, int> visited;

//배열 크기 순으로 정렬
bool comp(vector<int> a, vector<int> b){
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    
    vector<vector<int>> arr;
    
    for(int i = 1; i<s.length()-1; i++){
        //문자열 -> 배열
        if(s[i] == '{'){
            i++;
            vector<int> temp;
            int num = 0;
            while(s[i]!='}'){
                if(s[i] == ',') {
                    temp.push_back(num);
                    num = 0;
                }
                else num = num*10 + (s[i] - '0');
                i++;
            }
            temp.push_back(num);
            arr.push_back(temp);
        }
    }
    
    sort(arr.begin(), arr.end(), comp);
    
    for(auto i : arr){
        for(auto j : i){
            if(visited[j] == 0){
                visited[j] ++;
                answer.push_back(j);
                break;
            }
        }
    }
    return answer;
}