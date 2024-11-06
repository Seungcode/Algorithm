#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    int d = 0, p = 0, cnt = 0;
    
    for(int i = n-1; i >= 0; i--){
        d -= deliveries[i];
        p -= pickups[i];
        
        cnt = 0;
        
        while(d < 0 || p < 0){
            d += cap;
            p += cap;
            cnt ++;
        }
        
        answer += (i+1)*2*cnt;
    }
    return answer;
}