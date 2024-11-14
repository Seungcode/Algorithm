#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> arr;
int given[51][51];
int score[51];

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    for(int i = 1; i<=friends.size(); i++){
        arr[friends[i-1]] = i;
    }
    
    for(auto i : gifts){
        string temp;
        string name = "";
        for(auto j : i){
            if(j==' '){
                temp = name;
                name = "";
            }
            else name += j;
        }
        given[arr[name]][arr[temp]] --;
        given[arr[temp]][arr[name]] ++;
        score[arr[temp]]++;
        score[arr[name]]--;
    }
    
    for(int i = 1; i<=friends.size(); i++){
        int temp = 0;
        for(int j = 1; j<=friends.size(); j++){
            if(i==j) continue;
            if(given[i][j] > 0) temp ++;
            else if(given[i][j] == 0 && score[i] > score[j]) temp ++;
        }
        answer = max(answer, temp);
    }
    
    return answer;
}