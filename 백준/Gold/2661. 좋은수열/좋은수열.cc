#include <iostream>
#include <string>

using namespace std;

int N;

void solve(string tem){
    for (int i = 1; i <=  tem.size()/ 2; i++) {
        if (tem.substr(tem.size() - i, i) == tem.substr(tem.size() - 2 * i, i)) return;
    }
    if(tem.length() == N){
        cout<<tem;
        exit(0);
    }
    solve(tem + "1");
    solve(tem + "2");
    solve(tem + "3");

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;

    solve("");

    //문제유형 : 백트레킹
}
