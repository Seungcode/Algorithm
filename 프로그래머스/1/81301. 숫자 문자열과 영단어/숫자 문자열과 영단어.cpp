#include <string>
#include <map>

using namespace std;

int solution(string s) {
    
    //문자 map 초기화 (zero, 0)은 존재여부 확인을 위해 -1로 설정함
    map<string, int> arr = 
    {{"zero", -1}, 
     {"one", 1}, 
     {"two", 2}, 
     {"three", 3}, 
     {"four", 4}, 
     {"five", 5}, 
     {"six", 6}, 
     {"seven", 7}, 
     {"eight", 8}, 
     {"nine", 9}};

    int answer = 0;
    
    string temp = "";
    
    for(auto i : s){
        temp += i;
        
        //단일로 숫자를 나타낼 때
        if(i - '0' >= 0 && i - '0' <=9){
            answer = answer *10 + (i - '0');
            temp = "";
        }
        
        //영문일 때
        else if(arr[temp] != 0){
            //zero일 경우
            if(arr[temp] == -1){
                answer = answer * 10;
            }
            //zero가 아닐 경우
            else{
                answer = answer * 10 + arr[temp];
            }
            temp = "";
        }
    }
    return answer;
}