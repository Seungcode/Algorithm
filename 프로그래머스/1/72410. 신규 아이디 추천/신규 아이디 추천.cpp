#include <string>
#include <vector>
using namespace std;

string solution(string new_id) {
    //1단계
    for(int i = 0; i<new_id.length(); i++)
        new_id[i] = tolower(new_id[i]);
    
    //2단계
    string temp = "";
    for(int i = 0; i<new_id.length(); i++)
        if(new_id[i] == '-' || 
           new_id[i] == '_' || 
           new_id[i] == '.' || 
           (new_id[i] <= '9' && new_id[i] >= '0') || 
           (new_id[i] >= 'a' && new_id[i] <= 'z')) 
            temp += new_id[i];
    
    new_id = temp;
    
    //3단계
    temp = "";
    for(int i = 0; i<new_id.length(); i++){
        if(temp.back() == '.' && new_id[i] == '.') continue;
        temp += new_id[i];
    }
    
    //4단계
    new_id = temp;
    if(new_id[0] == '.') new_id.erase(new_id.begin());
    if(new_id.back() == '.') new_id.pop_back();
        
    //5단계
    if(new_id.length() == 0) new_id = "aaa";
    
    //6단계
    if(new_id.length() >= 16) new_id = new_id.substr(0, 15);
    if(new_id.back() == '.') new_id.pop_back();
    
    //7단계
    while(new_id.length() <= 2){
        new_id += new_id.back();
    }
    
    return new_id;
}