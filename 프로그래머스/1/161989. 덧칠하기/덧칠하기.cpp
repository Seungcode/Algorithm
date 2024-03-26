#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    
    //벽의 현 상태 저장
    vector<int> wall;
    wall.resize(n+1, 0);
    
    //칠해야 하는 벽 확인
    for(auto i : section){
        wall[i] = 1;
    }
    
    //만약 칠해야한다면? -> 롤러만큼 앞으로 이동(그 안에는 다 칠한거임)
    for(int i = 0; i<=n; i++){
        if(wall[i]==1){
            answer++;
            i+=m-1;
        }
    }
    
    //총 시간복잡도 O(N) -> 가장 큰 부분 -> 마지막 for문 -> 제일 커봐야 N만큼
    return answer;
}