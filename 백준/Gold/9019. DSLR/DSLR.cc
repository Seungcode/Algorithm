#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

int N, num;
bool visited[10001] = {false, };

void bfs(int i){
    queue<pair<int, string>> arr;
    arr.push({i, ""});
    while(!arr.empty()){
        int now = arr.front().first;
        string doing = arr.front().second;
        arr.pop();
        if(now==num){
            cout<<doing<<"\n";
            return;
        }
        if(!visited[(now*2)%10000]){
            visited[(now*2)%10000] = true;
            arr.push({(now*2)%10000, doing + "D"});
        }
        if(now-1>=0) {
            if (!visited[now - 1]) {
                visited[now - 1] = true;
                arr.push({now - 1, doing + "S"});
            }
        }
        if(now-1<0) {
            if (!visited[9999]) {
                visited[9999] = true;
                arr.push({9999, doing + "S"});
            }
        }
        if(!visited[(now%1000)*10 + now/1000]){
            visited[(now%1000)*10 + now/1000] = true;
            arr.push({(now%1000)*10 + now/1000, doing + "L"});
        }
        if(!visited[1000*(now%10) + now/10]){
            visited[1000*(now%10) + now/10] = true;
            arr.push({1000*(now%10) + now/10, doing + "R"});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;

    for(int i=0; i<N; i++){
        int a;
        cin>>a>>num;
        bfs(a);
        memset(visited, false, sizeof(visited));
    }
}
