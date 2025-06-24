#include <iostream>

using namespace std;

int main(){
    int a;
    string answer = "long int";
    
    cin>>a;
    
    while(a>4){
        answer = "long " + answer;
        a -= 4;
    }
    
    cout<<answer;
}