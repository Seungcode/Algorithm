#include <string>
#include <vector>
#include <map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    map <string, int> a;
    for(auto i : phone_book)
        a[i]++;
    for(auto i : phone_book){
        string temp = "";
        for(int j = 0; j<i.length()-1; j++){
            temp += i[j];
            if(a[temp]!=0){
                answer = false;
                return answer;
            }
        }
    }
    
    //문제유형 : 해싱
    return answer;
}