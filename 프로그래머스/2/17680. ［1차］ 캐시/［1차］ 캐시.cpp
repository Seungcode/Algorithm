#include <string>
#include <vector>
#include <map>
#include <algorithm>\

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    //존재여부와 캐시 내용을 담을 map, vector
    map<string, int> exist;
    vector<pair<int, string>> cache;  
    
    for(int i = 0; i<cities.size(); i++){
        string now = "";
        
        //대소문자가 섞일 수 있음 -> 다 소문자로 변환하기
        for(auto j : cities[i]) now += tolower(j);
        
        //캐시에 없을 경우
        if(exist[now] == 0){
            //자리가 남았다면
            if(cache.size() < cacheSize) cache.push_back({i+1, now});
            //캐시 사이즈가 0이라면
            else if(cacheSize == 0){
                answer += 5;
                continue;
            }
            //그 외의 경우
            else{
                sort(cache.begin(), cache.end());
                exist[cache[0].second] = 0;
                cache[0] = {i+1, now};
            }
            
            exist[now] = 1;
            
            answer += 5;
        }
        
        else{
            //이미 캐시에 해당 값이 있을경우
            for(int j = 0; j<cache.size(); j++){
                if(cache[j].second == now){
                    cache[j] = {i+1, now};
                    break;
                }
            }
            
            answer++;
        }
        
    }
    return answer;
}