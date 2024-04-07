#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    //현재 나온 종류
    map <int, int> arr;
    
    //총 몇 종이 나왔는지 확인
    for(auto i : nums){
        if(arr[i]==0) answer++;
        arr[i]++;
    }
    
    //나온 종류가 절반보다 많다면 갯수 변경
    answer = answer >= nums.size()/2 ? nums.size()/2 : answer;
    
    //문재유형 : 해시
    return answer;
}