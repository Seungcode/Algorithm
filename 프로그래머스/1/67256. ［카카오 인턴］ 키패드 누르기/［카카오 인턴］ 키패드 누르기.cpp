#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    //시작점 초기화
    pair<int, int> left = {3, 0};
    pair<int, int> right = {3, 2};
    
    //패드의 위치를 저장할 map 선언
    map <int, pair<int, int>> pad;
    
    //키보드 별 위치 저장
    pad[0] = {3, 1};
    for(int i = 0; i<9; i++)
        pad[i+1] = {i/3, i%3};
    
    //위치 계산
    for(auto i  : numbers){
        //왼손으로 가기
        if(i%3 == 1){
            answer += "L";
            left = pad[i];
        }
        //오른손으로 가기
        else if(i%3 == 0 && i!=0){
            answer += "R";
            right = pad[i];
        }
        //중간일 경우
        else{
            //같다면
            if(abs(left.first - pad[i].first) + abs(left.second - pad[i].second) == abs(right.first - pad[i].first) + abs(right.second - pad[i].second)){
                if(hand == "right"){
                    answer += "R";
                    right = pad[i];
                }
                else{
                    answer += "L";
                    left = pad[i];
                }
            }
            //오른손이랑 더 가깝다면
            else if(abs(left.first - pad[i].first) + abs(left.second - pad[i].second) > abs(right.first - pad[i].first) + abs(right.second - pad[i].second)){
                answer += "R";
                right = pad[i];
            }
            //왼손이랑 더 가깝다면
            else{
                answer += "L";
                left = pad[i];
            }
        }
    }
    
    //문제유형 : 구현
    
    return answer;
}