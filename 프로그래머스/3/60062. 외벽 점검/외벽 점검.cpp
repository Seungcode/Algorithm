#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 101;
    
    vector<int> v = weak;
    
    for(auto i : weak){
        v.push_back(i+n);
    }
    
    sort(dist.begin(), dist.end());
    
    do{
        for(int i = 0; i<weak.size(); i++){
            
            int start = v[i];
            int end = v[i + weak.size() - 1];
            
            for(int j = 0; j < dist.size(); j++){
                start += dist[j];
                if(start >= end){
                    answer = min(answer, j + 1);
                    break;
                }
                
                for(int z=i+1; z<i+v.size(); z++) {
                    if(v[z] > start) {
                        start = v[z];
                        break;
                    }
                }
            }
            
        }
    }while(next_permutation(dist.begin(), dist.end()));
    
    if(answer == 101) answer = -1;
    return answer;
}