#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    
    //정렬
    sort(d.begin(), d.end());
    
    //작은 것부터 지원해주고 예산이 적으면 break
    for(auto i : d){
        budget -= i;
        if(budget<0)
            break;
        answer++;
    }
    
    //문제유형 : 그리디
    return answer;
}