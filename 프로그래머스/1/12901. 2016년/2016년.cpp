#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    
    //날짜 저장용
    int day[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string d[7] = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    int date = 0;
    
    //날짜 계산
    for(int i=1; i<a; i++)
        date += day[i-1];
    date += b;
    date--;
    
    //요일 계산
    answer = d[date%7];
    
    //문제유형 : 구현
    return answer;
}