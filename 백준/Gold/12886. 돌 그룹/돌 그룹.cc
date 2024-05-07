#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, K;
int now[3];
bool arr[501][1001][1001] = {false, };

int bfs(){
    queue <pair<pair<int, int>, int>> q;
    q.push({{N, M}, K});

    while(!q.empty()){
        now[0] = q.front().first.first;
        now[1] = q.front().first.second;
        now[2] = q.front().second;

        sort(now, now+3);

        int a = now[0];
        int b = now[1];
        int c = now[2];

        q.pop();

        if(arr[a][b][c]) continue;

        if(a==b && b==c)
            return 1;

        if(a!=b){
            q.push({{a+a, b-a}, c});
        }
        if(a!=c){
                q.push({{a+a, b}, c-a});
        }
        if(b!=c){
            q.push({{a, b+b}, c-b});
        }
        arr[a][b][c] = true;
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;

    cout<<bfs();

    return 0;

    //문제유형 : bfs
}
