#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n,m;
string map[502];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main(void){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>map[i];
    }
    queue<pair<int,int> > que;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == 'W'){
                que.push(make_pair(i,j));
            }
        }
    }
    bool check = true;
    while(!que.empty()){
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
    
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(map[nx][ny] == 'S'){
                check = false;
                break;
            }
            if(map[nx][ny] == '.'){
                map[nx][ny] ='D';
            }
        }

    }
     if(!check){
            cout<<0<<"\n";
            return 0;
        }
        else {
            cout<<1<<"\n";
            for(int i=0; i<n; i++){
                cout<<map[i]<<"\n";
            }
            return 0;
        }
    return 0;
}