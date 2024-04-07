#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    for(auto i : arr){
        if(answer.size()==0)
            answer.push_back(i);
        else
            if(answer[answer.size()-1] != i) answer.push_back(i);
    }
    

    return answer;
}