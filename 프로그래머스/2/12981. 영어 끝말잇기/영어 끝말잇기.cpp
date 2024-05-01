#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map <string, int> bf;
    string before = "";
    
    for(int i = 0; i<words.size(); i++){
        if(bf[words[i]]!=0 || (before != "" && before[before.length()-1] != words[i][0])){
            answer.push_back(i%n + 1);
            answer.push_back(i/n + 1);
            return answer;
        }
        
        bf[words[i]]++;
        before = words[i];
    }
    
    answer.push_back(0);
    answer.push_back(0);
    
    //문제유형 : 구현
    
    return answer;
}