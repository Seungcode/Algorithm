#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct Node{
    int num;
    int like[4];
};

struct Empty{
    pair<int, int> loc;
    int like;
    int empty;

    bool operator<(Empty const & other) const{
        if(like == other.like){
            if(empty == other.empty){
                if(loc.first == other.loc.first)
                    return loc.second > other.loc.second;
                return loc.first > other.loc.first;
            }
            return empty < other.empty;
        }
        return like < other.like;
    }
};

int N;
Node arr[401];
queue<pair<int, int>> q;
pair<Node, int> location[21][21] = {};
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void input(){
    cin>>N;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            q.push({i, j});
            cin>>arr[i*N+j].num>>arr[i*N+j].like[0]>>arr[i*N+j].like[1]>>arr[i*N+j].like[2]>>arr[i*N+j].like[3];
        }
    }
}

void find(int x){
    Node now = arr[x];
    priority_queue<Empty> temp;
    while(!q.empty()){
        Empty current = {q.front(), 0, 0};
        q.pop();
        for(int i = 0; i<4; i++){
            int nx = current.loc.first + dx[i];
            int ny = current.loc.second + dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(location[nx][ny].first.num < 1) current.empty++;
            else if(find(begin(now.like), end(now.like), location[nx][ny].first.num) != end(now.like)){
                current.like++;
            }
        }
        temp.push(current);
    }
    location[temp.top().loc.first][temp.top().loc.second] = {now, 0};
    for(int i = 0; i<4; i++){
        int nx = temp.top().loc.first + dx[i];
        int ny = temp.top().loc.second + dy[i];
        if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
        if(location[nx][ny].first.num < 1) continue;
        if(find(begin(now.like), end(now.like), location[nx][ny].first.num) != end(now.like)){
            location[temp.top().loc.first][temp.top().loc.second].second++;
        }
        if(find(begin(location[nx][ny].first.like), end(location[nx][ny].first.like), now.num) != end(location[nx][ny].first.like)){
            location[nx][ny].second++;
        }
    }
    temp.pop();

    while(!temp.empty()){
        q.push(temp.top().loc);
        temp.pop();
    }
}

void solution() {
    input();
    for(int i = 0; i<N*N; i++){
        find(i);
    }
    int answer = 0;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            if(location[i][j].second == 0) continue;
            else if(location[i][j].second == 1) answer += 1;
            else if(location[i][j].second == 2) answer += 10;
            else if(location[i][j].second == 3) answer += 100;
            else if(location[i][j].second == 4) answer += 1000;
        }
    }
    cout<<answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}
