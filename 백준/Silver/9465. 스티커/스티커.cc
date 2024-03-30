#include <iostream>
#include <string>

using namespace std;

//테스트케이스의 수와 배열 선언
int T;
int arr[2][100001] = {0, };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //테스트케이스 수 입력받기
    cin>>T;
    
    for(int i = 0; i<T; i++){
        //숫자 갯수 입력
        int N;
        cin>>N;
        
        //점수 입력받기
        for(int z = 0; z<2; z++) {
            for (int j = 0; j < N; j++)
                cin >> arr[z][j];
        }
        
        //현재 스티커를 사용할 경우 -> 대각선 아래 값과 더함
        //사용하지 않을 경우 -> 바로 옆 값을 가져옴
        for(int j = 1; j<N; j++) {
            arr[0][j] = max(arr[0][j]+arr[1][j-1], arr[0][j-1]);
            arr[1][j] = max(arr[1][j] + arr[0][j-1], arr[1][j-1]);
        }
        
        //최대값 출력
        cout<<max(arr[0][N-1], arr[1][N-1])<<'\n';
    }
    
    //문제유형 : 다이나믹 프로그래밍
}