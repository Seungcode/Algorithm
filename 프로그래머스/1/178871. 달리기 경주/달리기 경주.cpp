#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    //순위를 담을 map p1 선언
    map<string, int> p1;
    
    //초기 순위 할당
    for(int i = 0; i<players.size(); i++){
        p1[players[i]] = i;        
    }
    
    //이름이 불릴 때 마다 직전 선수와 순위를 바꿈 -> 다른 선수들은 영향을 받지 않음!
    for(auto i : callings){
        players[p1[i]] = players[p1[i]-1];
        players[p1[i]-1] = i;
        p1[players[p1[i]]] ++;
        p1[i]--;
    }
    
    return players;
}