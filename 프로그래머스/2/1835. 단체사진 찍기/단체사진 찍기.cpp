#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
vector<string> condition;

bool validate(vector<char> arr){
    map<char, int> temp;
    
    for(int i = 0; i<8; i++)
        temp[arr[i]] = i + 1;
    
    for(auto i : condition){
        if(i[3] == '='){
            if(abs(temp[i[0]] - temp[i[2]]) - 1 != i[4] - '0') 
                return false; 
        }
        else if(i[3] == '>'){
            if(abs(temp[i[0]] - temp[i[2]]) - 1 <= i[4] - '0') 
                return false; 
        }
        else{
            if(abs(temp[i[0]] - temp[i[2]]) - 1 >= i[4] - '0') 
                return false; 
        }
    }
    return true;
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    vector<char> kakao = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    condition = data;
    int answer = 0;
    
    do{
        if(validate(kakao)) answer ++;
    }while(next_permutation(kakao.begin(), kakao.end()));
    return answer;
}