#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//테스트케이스의 수와 배열 선언
int T;
int build[1001] = {0, };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //테스트케이스 수 입력받기
    cin>>T;

    for(int i = 0; i<T; i++) {
        //도시의 수와 규칙의 수 입력받기
        int N, K;
        cin >> N >> K;

        //맨 처음 건물을 찾기 위한 배열 (무언가에 의해 세워지지 않으면 그게 첫 건물임)
        int arr[1001] = {0,};
        //해당 건물 이후에 세울 수 있는 건물을 담을 벡터
        vector<vector<int>> arr_;
        //지금 건설중인 건물을 넣어주기 위한 큐
        queue<int> building;
        //최종 시간을 담을 배열
        int result[1001] = {0,};
        //벡터 초기화
        arr_.resize(N + 1);

        //건물 당 소요시간 입력받기
        for (int j = 1; j <= N; j++)
            cin >> build[j];

        //규칙을 입력 받으면서 이전에 수행되어야하는 수를 계산하고, 규칙을 저장함
        for (int j = 0; j < K; j++) {
            int X, Y;
            cin >> X >> Y;
            arr[Y]++;
            arr_[X].push_back(Y);
        }

        //맨 처음 건물을 찾음
        for (int j = 1; j <= N; j++){
            if (arr[j] == 0) {
                building.push(j);
                result[j] = build[j];
            }
        }

        //계산
        while(!building.empty()){
            //현재 건물
            int v = building.front();
            building.pop();
            //이후 세울 수 있는 건물
            for(auto j : arr_[v]){
                //가장 오래걸리는 건물이 완성이 되어야 다음 건물을 세울 수 있으므로 맥스값 사용
                result[j] = max(result[j], result[v] + build[j]);
                //만약 현재 건물을 세우기 위한 이전 건물이 다 세워졌다면 -> 큐에 넣고 건물 건설
                if(--arr[j] == 0) building.push(j);
            }
        }

        //최종 건물을 입력받은 후 결과값 출력
        int end;
        cin>>end;
        cout<<result[end]<<'\n';
    }

    //문제유형 : 위상 정렬 (그래프 이론)
}