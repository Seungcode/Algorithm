#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    
    //문자열 저장
    vector<char> arr;
    
    //문자열 넣어주기
    for(int i = 0; i < s.length(); i++)
        arr.push_back(s[i]);
    
    //큰 것부터 정렬
    sort(arr.begin(), arr.end(), greater());
    
    //답 완성
    for(auto i : arr)
        answer += i;

    //문제유형 : 정렬
    return answer;
}