#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    //카드 순서를 나타내기 위한 map
    map <string, int> card;
    
    //직전의 카드 위치를 나타내기 위한 변수
    int c_1 = 0;
    int c_2 = 10;
    
    //카드 인덱스 값 정리 -> 1-10까지는 카드1, 그 이상은 카드2로 할당
    for(int i = 0; i<cards1.size(); i++)
        card[cards1[i]] = i+1;    
    for(int i = 0; i<cards2.size(); i++)
        card[cards2[i]] = i+11;
    
    //카드의 인덱스 넘버에 따라 만일 이후에 나온 값이 더 작다면? -> No출력 / 끝까지 문제 없을 경우 -> Yes출력
    for(auto i : goal){
        if(card[i] <= 10){
            if(c_1+1 != card[i])
                return "No";
            c_1 = card[i];
        }
        else{
            if(c_2+1 != card[i])
                return "No";
            c_2 = card[i];
        }
    }
    
    //시간복잡도 O(N) -> 최대 O(20)
    return "Yes";
}