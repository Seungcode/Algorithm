#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i = 0; i<n; i++){
        //현재 수
        int first = arr1[i];
        int second = arr2[i];
        
        //임시 문자열
        string temp = "";
        
        for(int j = 0; j<n; j++){
            //둘 중 하나라도 1일경우 -> #추가
            if(first%2 || second%2) temp += '#';
            //둘 다 0일경우 -> 공백 추가
            else temp += ' ';
            first /= 2;
            second /= 2;
        }
        
        //문자열 역으로 만들기
        string result = "";
        for(int j = n-1; j>=0; j--) result += temp[j];
        
        answer.push_back(result);
    }
    return answer;
}