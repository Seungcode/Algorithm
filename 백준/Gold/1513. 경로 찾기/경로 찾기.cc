#include <iostream>
#include <map>

using namespace std;

//배열의 크기와 오락실의 갯수를 저장기 위한 변수 및 배열 선언
int N, M, C;
int arr[51][51][51][51] = {0, };
map <pair<int, int>, int> play;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M>>C;

    //오락실 입력받기 -> i는 오락실 번호
    for(int i = 1; i <= C; i++){
        int x, y;
        cin>>x>>y;
        play[{x, y}] = i;
    }

    //처음 자리가 오락실일 경우와 아닐 경우를 나누어 계산
    if(play[{1, 1}]!=0)
        arr[1][1][play[{1, 1}]][1] = 1;
    else
        arr[1][1][0][0] = 1;

    //경로 계산
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=M; j++){
            //시작점일 경우 -> 패스
            if(i==1 && j==1)
                continue;
            //오락실일 경우 -> 더 낮은 번호의 오락실로 가는 경우를 다 더해서 배열에 저장
            if(play[{i, j}]!=0){
                for(int k = 0; k<play[{i, j}]; k++) {
                    for (int z = 0; z < C; z++)
                        arr[i][j][play[{i, j}]][z + 1] += (arr[i - 1][j][k][z] + arr[i][j - 1][k][z])%1000007;
                }
            }
            //오락실이 아닐 경우 -> 위 + 왼쪽으로 값 저장
            else{
                for(int k = 0; k<=C; k++){
                    for(int z = 0; z<=C; z++)
                        arr[i][j][k][z] = (arr[i-1][j][k][z] + arr[i][j-1][k][z])%1000007;
                }
            }
        }
    }

    //각 카운트별로 합을 구해 출력
    for(int i = 0; i<=C; i++){
        int temp = 0;
        for(int j = 0; j<=C; j++)
            temp = (temp + arr[N][M][j][i])%1000007;
        cout<<temp<<" ";
    }

    //문제유형 : 다이나믹 프로그래밍
}