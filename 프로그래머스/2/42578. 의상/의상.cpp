#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> arr;
    
    for(auto i : clothes)
        arr[i[1]]++;
    
    for(auto i : arr)
        answer *= i.second+1;
    
    answer --;
    
    return answer;
    
    //문제유형 : 해싱
}