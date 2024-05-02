#include <iostream>
#include <cstring>

using namespace std;

int N, M, K;
string word;
char arr[101][101];
int cnt[101][101][81];
long long int answer = 0;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int dfs (int x, int y, int idx){
    if(cnt[x][y][idx]!=-1)
        return cnt[x][y][idx];

    if(idx == word.length()-1)
        return 1;

    cnt[x][y][idx] = 0;
    
    for(int i = 0; i<4; i++){
        int nx = x;
        int ny = y;
        for(int j = 0; j<K; j++){
            nx += dx[i];
            ny += dy[i];
            if(nx >= N || ny >= M || nx < 0 || ny < 0)
                break;
            if(arr[nx][ny] == word[idx+1])
                cnt[x][y][idx] += dfs(nx, ny, idx+1);
        }
    }

    return cnt[x][y][idx];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M>>K;
    
    memset(cnt, -1, sizeof(cnt));

    for(int i = 0; i<N; i++){
        string a;
        cin>>a;
        for(int j = 0; j<M; j++)
            arr[i][j] = a[j];
    }

    cin>>word;

    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++)
            if(arr[i][j] == word[0]) answer += dfs(i, j, 0);
    }

    cout<<answer;

    //문제유형 : dfs + dp

    return 0;
}
