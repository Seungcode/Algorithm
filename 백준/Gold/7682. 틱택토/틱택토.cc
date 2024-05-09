#include <iostream>
#include <map>

using namespace std;

char arr[3][3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true){
        string a;
        int x = 0;
        int o = 0;
        map <char, int> q;
        cin>>a;
        if(a=="end") break;
        for(int i = 0; i<9; i++) {
            if (a[i] == 'X') x++;
            else if (a[i] == 'O') o++;
            arr[i / 3][i % 3] = a[i];
        }
        if(x < o || x > o + 1) {
            cout<<"invalid"<<"\n";
            continue;
        }
        if((arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2])&&arr[0][0]!='.') {
            q[arr[0][0]] ++;
            arr[0][0] = '.';
            arr[1][1] = '.';
            arr[2][2] = '.';
        }
        if((arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0])&&arr[0][2]!='.') {
            q[arr[0][2]] ++;
            arr[0][2] = '.';
            arr[1][1] = '.';
            arr[2][0] = '.';
        }
        if((arr[0][0] == arr[0][1] && arr[0][1] == arr[0][2])&&arr[0][2]!='.') {
            q[arr[0][0]] ++;
            arr[0][0] = '.';
            arr[0][1] = '.';
            arr[0][2] = '.';
        }
        if((arr[1][0] == arr[1][1] && arr[1][1] == arr[1][2])&&arr[1][2]!='.') {
            q[arr[1][0]] ++;
            arr[1][0] = '.';
            arr[1][1] = '.';
            arr[1][2] = '.';
        }
        if((arr[2][0] == arr[2][1] && arr[2][1] == arr[2][2])&&arr[2][0]!='.') {
            q[arr[2][0]] ++;
            arr[2][0] = '.';
            arr[2][1] = '.';
            arr[2][2] = '.';
        }
        if((arr[0][0] == arr[1][0] && arr[1][0] == arr[2][0])&&arr[0][0]!='.') {
            q[arr[0][0]] ++;
            arr[0][0] = '.';
            arr[1][0] = '.';
            arr[2][0] = '.';
        }
        if((arr[0][1] == arr[1][1] && arr[1][1] == arr[2][1])&&arr[0][1]!='.') {
            q[arr[0][1]] ++;
            arr[0][1] = '.';
            arr[1][1] = '.';
            arr[2][1] = '.';
        }
        if((arr[0][2] == arr[1][2] && arr[1][2] == arr[2][2])&&arr[0][2]!='.') {
            q[arr[0][2]] ++;
            arr[0][2] = '.';
            arr[1][2] = '.';
            arr[2][2] = '.';
        }
        if(q['X'] + q['O'] > 1) cout<<"invalid"<<"\n";
        else if((q['X']== 1 && x > o) || (q['O'] == 1 && x == o) || (q['X'] + q['O'] ==0 && x+o == 9)) cout<<"valid"<<"\n";
        else cout<<"invalid"<<"\n";
    }
    return 0;

    //문제유형 : 구현
}
