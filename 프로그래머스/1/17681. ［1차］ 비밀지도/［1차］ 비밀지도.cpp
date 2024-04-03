#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i = 0; i<n; i++){
        string secret = "";
        string final_secret = "";
        
        //2진수로 바꾸어 지도 생성 -> 반대로 뒤집어줘야함
        for(int j = 0; j<n; j++){
            if(arr1[i]%2==1 || arr2[i]%2==1)
                secret += '#';
            else
                secret += ' ';
            arr1[i] = arr1[i]/2;
            arr2[i] = arr2[i]/2;
        }
        
        //뒤집어주기
        for(int j = n-1; j>=0; j--)
            final_secret += secret[j];
        
        //답 넣어주기
        answer.push_back(final_secret);
    }
    
    //문제유형 : 구현 
    return answer;
}