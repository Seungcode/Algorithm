#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    map<string, int> sale;
    
    for(int i = 0; i<discount.size(); i++){
        if(i>9)
            sale[discount[i-10]]--;
        sale[discount[i]]++;
        
        int cnt = 0;
        for(int j = 0; j<want.size(); j++){
            if(sale[want[j]] >= number[j]) cnt++;
            else break;
        }
        if(cnt == want.size()) answer++;
    }
    return answer;
}