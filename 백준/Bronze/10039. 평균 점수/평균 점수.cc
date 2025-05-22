#include <iostream>

using namespace std;

int main(){
    int answer = 0;
    
    for(int i = 0; i<5; i++){
        int a;
        cin>>a;
        answer += max(40, a);
    }
    
    cout<<answer/5;
}