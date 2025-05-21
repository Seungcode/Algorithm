#include <iostream>

using namespace std;

int main(){
    int h, m, a;
    cin>>h>>m>>a;
    
    cout<<(h + (m+a)/60)%24 << " "<<(m+a)%60;
}