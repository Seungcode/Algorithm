#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    //변수 설정
    string answer = "";
    vector<int> arr;
    string temp = "";
    
    //값 비교
    for(int i = 0; i<s.length(); i++){
        if(s[i]==' '){
            arr.push_back(stoi(temp));
            temp = "";
        }
        else temp += s[i];
    }
    
    arr.push_back(stoi(temp));
    
    //정렬
    sort(arr.begin(), arr.end());
    
    answer = to_string(arr[0]) + " " + to_string(arr[arr.size()-1]);
    
    //문제유형 : 문자열
    
    return answer;
}