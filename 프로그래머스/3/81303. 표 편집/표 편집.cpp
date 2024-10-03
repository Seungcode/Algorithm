#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//연결리스트
struct Node{
    int up;
    int now;
    int down;
};

//배열
vector<Node> arr;

//삭제된 값 관리
vector<Node> deleted;

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    
    //배열 초기화
    for(int i = 0; i<n; i++) arr.push_back({i-1, i, i+1});
    
    for(auto i : cmd){
        //올라가기
        if(i[0] == 'U') {
            int a = stoi(i.substr(2, i.length() - 2));
            for(int j = 0; j<a; j++) k = arr[k].up;
        }
        
        //내려가기
        else if(i[0] == 'D') {
            int a = stoi(i.substr(2, i.length() - 2));
            for(int j = 0; j<a; j++) k = arr[k].down;
        }
        
        //삭제
        else if(i[0] == 'C') {
            deleted.push_back(arr[k]);
            if(arr[k].down != n)
                arr[arr[k].down].up = arr[k].up;
            if(arr[k].up != -1)
                arr[arr[k].up].down = arr[k].down;
            
            if(arr[k].down == n) k = arr[k].up;
            else k = arr[k].down;
            
        }
        
        //복구
        else if(i[0] == 'Z') {
            arr.push_back(deleted.back());
            if(deleted.back().down != n)
                arr[deleted.back().down].up = deleted.back().now;
            if(deleted.back().up != -1)
                arr[deleted.back().up].down = deleted.back().now;
            deleted.pop_back();
        }
    }
    
    //정답 만들기
    for(int i = 0; i<n; i++) 
        answer += 'O';
    
    while(!deleted.empty()){
        answer[deleted.back().now] = 'X';
        deleted.pop_back();
    }
    
    return answer;
}