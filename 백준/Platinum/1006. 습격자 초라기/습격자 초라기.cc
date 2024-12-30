#include <iostream>

using namespace std;

int T, N, W;
int visited[10001][3];
int arr[10001][2];
int min_num = 20002;

//방문 배열 초기화
void initArr(){
    for(int j = 0; j<=N; j++) {
        for(int z = 0; z < 3; z++)
            visited[j][z] = 0;
    }

    for(int j = 0; j<=N; j++) {
        for(int z = 0; z < 2; z++)
            arr[j][z] = 0;
    }
}

void logic(){
    for(int i = 2; i<=N; i++){
        //만일 합이 더 크다면 -> 현재 칸 이전 칸 총 2개의 소대를 보내야 함
        int fir_fill = arr[i][0] + arr[i - 1][0] <= W ? 1 : 2;
        int sec_fill = arr[i][1] + arr[i - 1][1] <= W ? 1 : 2;
        int whl_fill = arr[i][0] + arr[i][1] <= W ? 1 : 2;

        //기본 -> [2] + 1 즉, 이전까지 보낸 내용 + 한 소대 더 & 이전내용까지 동일 + 현재 보내야 하는 소대를 비교
        visited[i][0] = min(visited[i - 1][2] + 1, visited[i - 1][1] + fir_fill);
        visited[i][1] = min(visited[i - 1][2] + 1, visited[i - 1][0] + sec_fill);

        //내부와 외부를 채웠다면 최종적으로 해당 칸을 채우기 위해 필요한 수 정리
        visited[i][2] = min(visited[i][0] + 1, visited[i][1] + 1);
        visited[i][2] = min(visited[i][2], visited[i - 1][2] + whl_fill);
        visited[i][2] = min(visited[i][2], visited[i - 2][2] + fir_fill + sec_fill);
    }
}

void solution(){
    //원형 고려 -> 4개지의 경우를 구해주기
    visited[1][0] = visited[1][1] = 1;
    visited[1][2] = ((arr[1][0] + arr[1][1]) <= W) ? 1 : 2;
    logic();
    min_num = visited[N][2];

    visited[0][2] = 20002;
    if (arr[1][0] + arr[N][0] <= W) {
        visited[1][0] = 1;
        visited[1][1] = 20002;
        visited[1][2] = 2;

        logic();
        min_num = min(min_num, visited[N][1]);
    }

    if (arr[1][1] + arr[N][1] <= W) {
        visited[1][0] = 20002;
        visited[1][1] = 1;
        visited[1][2] = 2;

        logic();
        min_num = min(min_num, visited[N][0]);
    }

    if ((arr[1][0] + arr[N][0] <= W) && (arr[1][1] + arr[N][1] <= W)) {
        visited[1][0] = visited[1][1] = 20002;
        visited[1][2] = 2;

        logic();
        min_num = min(min_num, visited[N-1][2]);
    }

    cout<<min_num<<endl;
}

//입력받기
void input(){
    cin>>T;

    for(int i = 0; i<T; i++) {
        initArr();

        cin>>N>>W;

        for(int j = 1; j<=N; j++) cin>>arr[j][0];
        for(int j = 1; j<=N; j++) cin>>arr[j][1];

        if(N==1){
            if(arr[1][0] + arr[1][1] <= W) cout<<1<<endl;
            else cout<<2<<endl;
            continue;
        }

        solution();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();

    return 0;
}