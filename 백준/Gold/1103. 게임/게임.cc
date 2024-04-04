    #include <iostream>

    using namespace std;

    //배열의 크기
    int N, M;
    //보드 저장
    char arr[51][51];
    //방문위치 확인 -> 가는 길에 이미 방문한 길이 있다면? -> 무한대 가능
    bool visited[51][51] = {false, };
    //최대로 할 수 있는 크기
    int dp[51][51] = {0, };
    //좌표변경용
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    int dfs(int x, int y){

        //범주를 벗어날 경우
        if(x >= N || y >= M || x<0 || y<0)
            return 0;

        //구멍일 경우
        if(arr[x][y] == 'H')
            return 0;

        //무한대가 가능할 경우
        if(visited[x][y]) {
            cout << -1;
            exit(0);
        }

        //이미 저장된 값이 있다면
        if(dp[x][y]!=0)
            return dp[x][y];

        //다음 위치로 이동
        visited[x][y] = true;

        for(int i = 0; i<4; i++)
            dp[x][y] = max(dp[x][y], dfs(x + (arr[x][y]-'0')*dx[i], y+(arr[x][y]-'0')*dy[i])+1);

        visited[x][y] = false;

        return dp[x][y];
    }

    int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        cin>>N>>M;

        for(int i = 0; i<N; i++){
            string a;
            cin>>a;
            for(int j = 0; j<M; j++)
                arr[i][j] = a[j];
        }

        cout<<dfs(0, 0);

        //문제유형 : dfs
    }