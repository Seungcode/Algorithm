#include <string>
#include <vector>
#include <map>

using namespace std;

int score_first[7] = {3, 2, 1, 0, 0, 0, 0};
int score_second[7] = {0, 0, 0, 0, 1, 2, 3};
map<char, int> arr;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    //점수 집계
    for(int i = 0; i<survey.size(); i++){
        arr[survey[i][0]] += score_first[choices[i]-1];
        arr[survey[i][1]] += score_second[choices[i]-1];
    }
    
    //성격 유형 조합하기
    answer += arr['R'] < arr['T'] ? 'T' : 'R';
    answer += arr['C'] < arr['F'] ? 'F' : 'C';
    answer += arr['J'] < arr['M'] ? 'M' : 'J';
    answer += arr['A'] < arr['N'] ? 'N' : 'A';
    
    return answer;
}