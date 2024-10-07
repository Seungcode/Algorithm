#include <string>
#include <vector>
#include <map>

using namespace std;

map <int, pair<int, int>> pad;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    pad[0] = {3, 1};
    for(int i = 1; i<10; i++) pad[i] = {(i-1) / 3, (i-1) % 3};
    
    pair<int, int> r_h = {3, 0};
    pair<int, int> l_h = {3, 2};
    
    char p_h = hand == "right" ? 'R' : 'L' ;
    
    for(auto i : numbers){
        //왼 손 사용
        if(i % 3 == 1) {
            answer += 'L';
            l_h = pad[i];
        }
        
        //오른 손 사용
        else if(i % 3 == 0 && i != 0) {
            answer += 'R';
            r_h = pad[i];
        }
        
        //중간 열 일 때
        else{
            pair<int, int> pad_l = pad[i];
            
            //거리가 같을 때
            if(abs(pad_l.first - r_h.first) + abs(pad_l.second - r_h.second) 
               == abs(pad_l.first - l_h.first) + abs(pad_l.second - l_h.second)){
                if(p_h == 'L') l_h = pad[i];
                else r_h = pad[i];
                answer += p_h;
            }
            
            //왼손이 더 가까울 때
            else if(abs(pad_l.first - r_h.first) + abs(pad_l.second - r_h.second) 
               > abs(pad_l.first - l_h.first) + abs(pad_l.second - l_h.second)){
                answer += 'L';
                l_h = pad[i];
            }
            
            //오른손이 더 가까울 때
            else{
                answer += 'R';
                r_h = pad[i];
            }
        }
    }
    
    return answer;
}