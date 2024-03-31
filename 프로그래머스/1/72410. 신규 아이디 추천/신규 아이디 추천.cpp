#include <string>
#include <deque>
using namespace std;

string solution(string new_id) {
    string answer = "";
    
    //erase 사용을 위해 deque선언
    deque <char> arr;
    
    //문자열 담아주기
    for(int i = 0; i<new_id.length(); i++)
        arr.push_back(new_id[i]);
    
    //1단계
    for(int i = 0; i<arr.size(); i++)
        if(arr[i] - 'A' < 26 && arr[i]-'A' >= 0) arr[i] += 32;
    
    //2단계
    for(int i = 0; i<arr.size(); i++){
        if(arr[i] == '-' || 
           arr[i] == '_' || 
           arr[i] == '.' || 
           (arr[i] - '0' >= 0 && arr[i] - '0' <= 9) || 
           (arr[i] - 'a' >= 0 && arr[i] - 'a' < 26))
            continue;
        
        else{
            arr.erase(arr.begin() + i);
            i--;
        }
    }
    
    //3단계
    for(int i = 1; i<arr.size(); i++){
        if(arr[i] == '.' && arr[i-1] == '.'){
            arr.erase(arr.begin() + i);
            i--;
        }
    }
    
    //4단계
    if(!arr.empty())
        if(arr.front() == '.') arr.pop_front();
    if(!arr.empty())
        if(arr.back() == '.') arr.pop_back();
    
    //5단계
    if(arr.empty()) arr.push_back('a');
    
    //6단계
    while(arr.size() >= 16)
        arr.pop_back();
    if(arr.back() == '.') arr.pop_back();
    
    //7단계
    while(arr.size() < 3)
        arr.push_back(arr.back());
    
    //정답 생성
    for(auto i : arr)
        answer+=i;
    
    //문제유형 : 구현
    return answer;
}