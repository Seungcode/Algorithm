#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    //중복여부 확인용 배열
    map<int, int> arr;
    
    //합을 구한 후 그 값이 이미 있으면(value값이 0이 아니면) -> 배열에 안넣음
    for(int i = 0; i<numbers.size(); i++){
        for(int j = i+1; j<numbers.size(); j++){
            if(arr[numbers[i] + numbers[j]] == 0) answer.push_back(numbers[i] + numbers[j]);
            arr[numbers[i] + numbers[j]]++;
        }
    }
    
    //정렬
    sort(answer.begin(), answer.end());
    
    //문제유형 : 구현
    return answer;
}