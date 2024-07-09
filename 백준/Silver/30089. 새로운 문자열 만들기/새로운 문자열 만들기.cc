#include <iostream>
#include <algorithm>

using namespace std;

int T;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    for(int i = 0; i < T; i++){
        string a, b;
        cin>>a;
        b  = a;
        reverse(b.begin(), b.end());
        int cnt = 0;

        for(int j = 0; j < a.length(); j++){
            if(a[j] == b[cnt])
                cnt++;
            else cnt = 0;
        }

        for(int j = cnt; j < b.length(); j++)
            a += b[j];

        cout<<a<<endl;
    }

    return 0;

    //문제유형 : 문자열
}
