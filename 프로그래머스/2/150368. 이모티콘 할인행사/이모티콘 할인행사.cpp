#include <string>
#include <vector>
#include <map>

using namespace std;

//변수 설정
vector<vector<int>> u;
vector<int> e;
vector<int> u_e[5];
map<int, int> buy;
vector<int> answer;

//재귀 함수
void find(int sale, int n){
    //다 돌았을 경우
    if(n==e.size()){
        int plus = 0;
        int cnt = 0;
        //플러스 가입자와 아닌 경우를 나눠 계산
        for(int i = 0; i<u.size(); i++){
            if(buy[i]<u[i][1]) cnt+=buy[i];
            else plus++;
        }
        //처음일 경우
        if(answer.empty()){
            answer.push_back(plus);
            answer.push_back(cnt);
            return;
        }
        //플러스 가입자가 같은 경우
        else if(answer[0] == plus){
            answer[1] = (max(cnt, answer[1]));
            return;
        }
        //플러스 가입자가 더 많은 경우
        else if(answer[0] < plus){
            answer[0] = plus;
            answer[1] = cnt;
            return;
        }
        return;
    }
    
    //가격 계산
    int price = e[n]*0.1*(10-sale);
    
    //구매하는 사람들에게 더해주기
    for(int i = sale; i>=0; i--){
        for(int j = 0; j<u_e[i].size(); j++){
            buy[u_e[i][j]] += price;
        }
    }
    
    //다음 이모티콘으로
    for(int i = 1; i<=4; i++)
        find(i, n+1);
    
    //값 지워주기
    for(int i = sale; i>=0; i--){
        for(int j = 0; j<u_e[i].size(); j++){
            buy[u_e[i][j]] -= price;
        }
    }
    
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    u = users;
    e = emoticons;
    
    //할인율 저장
    for(int i = 0; i<users.size(); i++){
        if(users[i][0]%10==0){
            u_e[users[i][0]/10].push_back(i);
        }
        else
            u_e[(users[i][0]/10)+1].push_back(i);
    }
    
    for(int i = 1; i<=4; i++)
        find(i, 0);
    
    //문제 유형 : 완탐
    return answer;
}