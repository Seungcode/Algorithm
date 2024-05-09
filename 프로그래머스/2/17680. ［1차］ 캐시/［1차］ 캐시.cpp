#include <string>
#include <vector>
#include <map>
#include <deque>
#include <cctype>\

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    map<string, int> arr;
    deque<string> q;
    
    for(int i = 0; i<cities.size(); i++){
        string temp = cities[i];
        for(int j = 0; j<temp.length(); j++)
            temp[j] = tolower(temp[j]);
        cities[i] = temp;
    }
    
    for(int i = 0; i<cities.size(); i++){
        if(arr[cities[i]] == 1) {
            answer ++;
            for(int j = 0; j<q.size(); j++)
                if(cities[i] == q[j]) q.erase(q.begin() + j);
            q.push_back(cities[i]);
        }
        else {
            answer+=5;
            q.push_back(cities[i]);
            arr[cities[i]]++;
            if(q.size() > cacheSize){
                arr[q.front()] --;
                q.pop_front();
            }
        }
    }
    
    //문제유형 : 구현
    
    return answer;
}