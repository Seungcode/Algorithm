#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    //벡터 생성 -> 값 넣어주고 -> 정렬 -> 원하는 값 가져오기
    for(auto i : commands){
        vector<int> arr;
        for(int j = i[0]-1; j<i[1]; j++)
            arr.push_back(array[j]);
        sort(arr.begin(), arr.end());
        answer.push_back(arr[i[2]-1]);
    }
    
    //문제유형 : 구현
    
    return answer;
}