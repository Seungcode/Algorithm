#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
char ds[4] = {'d', 'l', 'r', 'u'};

priority_queue<pair<string, pair<int, int>>, vector<pair<string, pair<int, int>>>, greater<>> q;

string solution(int n, int m, int x, int y, int r, int c, int k) {
    if(abs(r-x) + abs(c-y) > k) return "impossible";
    
    q.push({"", {x, y}});
    
    while(!q.empty()){
        string noun = q.top().first;
        pair<int, int> now = q.top().second;
        q.pop();
        
        if(abs(r-now.first) + abs(c-now.second) + noun.length()> k
          || ((abs(r-now.first) + abs(c-now.second))%2 != (k - noun.length())%2)) 
            continue;
        
        if(noun.length() == k){
            if(r != now.first || c != now.second) continue;
            return noun;
        }
        
        for(int i = 0; i<4; i++){
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];
            if(nx<=0 || ny<=0 || nx > n || ny > m) continue;
            q.push({noun + ds[i], {nx, ny}});
        }
    }
    
    return "impossible";
}