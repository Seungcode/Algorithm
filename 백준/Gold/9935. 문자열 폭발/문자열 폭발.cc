#include <iostream>
#include<queue>

using namespace std;

string a, b;
string answer = "";
deque <char> arr;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>a>>b;

    //deque에 값 넣으면서 배열의 크기가 주어진 문자열보다 크면 pop을 반복
    for(int i = 0; i<a.length(); i++){
        arr.push_back(a[i]);
        if(arr.size() >= b.length()){
            int cnt = 0;
            for(int j = 0; j<b.length(); j++){
                if(arr[arr.size()-1-j] != b[b.length()-1-j])
                    break;
                cnt++;
            }
            if(cnt == b.length()){
                for(int j = 0; j<b.length(); j++){
                    arr.pop_back();
                }
            }
        }
    }

    //답 구하기
    for(auto i : arr)
        answer+=i;
    
    //공백일경우
    if(answer == "")
        answer = "FRULA";

    cout<<answer;
    
    //문제유형 : 문자열
}