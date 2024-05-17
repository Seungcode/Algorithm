#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
string a, b, c;
int flag = 0;
bool visited[201][201] = {false, };

void make_word(int i, int j, string now){
    if(now.length() == c.length()) {
        flag = 1;
        return;
    }
    if(c[now.length()] == a[i]) {
        if(!visited[i+1][j]) {
            visited[i+1][j] = true;
            make_word(i + 1, j, now + a[i]);
        }
    }
    if(c[now.length()] == b[j]) {
        if(!visited[i][j+1]) {
            visited[i][j+1] = true;
            make_word(i, j + 1, now + b[j]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;

    for(int i = 1; i <= N; i++) {
        flag = 0;
        cin>>a>>b>>c;
        make_word(0, 0, "");
        if(flag == 0) cout<<"Data set "<<i<<": no"<<"\n";
        else cout<<"Data set "<<i<<": yes"<<"\n";
        memset(visited, false, sizeof(visited));
    }

    return 0;

    //문제유형 : bfs
}
