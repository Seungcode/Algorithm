#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

string N, L;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>L;

    while(N.length()!=L.length()){
        if(L[L.length()-1] == 'B') {
            L = L.substr(0, L.length()-1);
            reverse(L.begin(), L.end());
        }
        else
            L = L.substr(0, L.length()-1);
    }

    if(N==L)
        cout<<1;
    else
        cout<<0;
    
    //문제유형 : greedy

    return 0;
}
