#include <string>
#include <vector>
#include <queue>

using namespace std;

//우선순위큐를 사용하기 위한 구조체
struct file{
    string head;
    int number;
    int index;
    string name;
    
    /*두개가 같을 경우 -> 인덱스
    헤드가 같을 경우 -> 넘버*/
    bool operator<(const file& other) const{
        if(head == other.head && number == other.number) return index > other.index;
        else if(head == other.head) return number > other.number;
        return head > other.head;
    }
};

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    priority_queue<file> arr;
    
    for(int i = 0; i<files.size(); i++){
        string head = "";
        int number = 0;
        
        //head 생성
        int j = 0;
        for(; j < files[i].length(); j++){
            if(files[i][j] - '0' <= 9 && files[i][j] - '0' >= 0) break;
            head += tolower(files[i][j]);
        }
        
        //number 생성
        for(; j < files[i].length(); j++){
            if(files[i][j] - '0' <= 9 && files[i][j] - '0' >= 0) number = number*10 + (files[i][j] - '0');
            else break;
        }
        
        //우선순위큐에 저장
        arr.push({head, number, i, files[i]});
    }
    
    //정답 배열에 저장
    while(!arr.empty()){
        answer.push_back(arr.top().name);
        arr.pop();
    }
    
    return answer;
}