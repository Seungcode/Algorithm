#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> op = {'*', '+', '-'};
vector<char> oper;
vector<long long> num;

long long cacu(long long a, long long b, char c){
    if(c=='-') return a-b;
    else if(c=='+') return a+b;
    else return a*b;
}

long long solution(string expression) {
    long long answer = 0;
    
    string tem = "";
    
    for(auto i : expression){
        if(i=='*' || i=='-' || i=='+'){
            num.push_back(stoi(tem));
            tem = "";
            oper.push_back(i);  
        }
        else tem += i;
    }
    num.push_back(stoi(tem));
    
    do{
        vector<char> tem_op = oper;
        vector<long long> temp_num = num;
        for(int i = 0; i<3; i++){
            for(int j = 0; j < tem_op.size(); j++){
                if(tem_op[j] == op[i]){
                    temp_num[j] = cacu(temp_num[j], temp_num[j+1], op[i]);
                    temp_num.erase(temp_num.begin()+j+1);
                    tem_op.erase(tem_op.begin() + j);
                    j--;
                }
            }
        }
        answer = max(answer, abs(temp_num[0]));
    }while(next_permutation(op.begin(), op.end()));
    
    return answer;
}