#include <iostream>
#include <queue>

using namespace std;

int N, K;
bool visited[500001][2] = {false, };

void input(){
    cin>>N>>K;
}

void solution(){
    input();

    queue<pair<int, int>> q;

    q.push({N, 0});

    int idx = 1;

    while(!q.empty()){
        auto [now, time] = q.front();
        q.pop();

        if(now == K){
            cout<<time;
            return;
        }

        int before = now -1;
        if(before >= 0 && !visited[before][(time + 1)%2]){
            visited[before][(time + 1)%2] = true;
            q.push({before, time + 1});
        }

        int next = now + 1;
        if(next <= 500000 && !visited[next][(time + 1)%2]){
            visited[next][(time + 1)%2] = true;
            q.push({next, time + 1});
        }

        int multi = now + now;
        if(multi <= 500000 && !visited[multi][(time + 1)%2]){
            visited[multi][(time + 1)%2] = true;
            q.push({multi, time + 1});
        }

        if(!q.empty() && time != q.front().second){
            K += idx;
            if(K > 500000) break;
            if(visited[K][(time+1)%2]){
                cout<<time + 1;
                return;
            }
            idx ++;
        }
    }

    cout<<-1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solution();
}
