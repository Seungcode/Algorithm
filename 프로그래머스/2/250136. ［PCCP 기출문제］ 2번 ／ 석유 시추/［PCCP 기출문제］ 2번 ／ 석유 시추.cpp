#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;


//전역 변수 설정
bool visited[501][501] = {false, };
map<int, int> arr;
int max_cnt[501] = {0, };
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

//각 원유 덩어리 별 번호 넘버링을 하는 동시에 덩어리 별 칸의 수 체크
void bfs(int i, int j, int cnt, vector<vector<int>>& temp){
    queue <pair<int, int>> q;
    map <int, int> for_i;
    q.push({i, j});
    temp[i][j] = 0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        for_i[y]++;
        arr[cnt]++;
        q.pop();
        for(int i = 0; i<4; i++){
            int tx = x + dx[i];
            int ty = y + dy[i];
            if(tx<0 || tx >= temp.size() || ty<0 || ty>=temp[0].size())
                continue;
            if(temp[tx][ty]==1){
                temp[tx][ty] = 0;
                q.push({tx, ty});
            }
        }
    }
    for(auto i : for_i)
        max_cnt[i.first] += arr[cnt];
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    
    //덩어리 넘버링 -> 0과 1은 배열에서 사용하기 때문에 2부터 시작
    int cnt = 2;
    
    //덩어리별로 bfs를 시행하며 확인
    for(int j =  0; j<land[0].size(); j++){
        int temp_answer = 0;
        map<int, int> temp;
        for(int i = 0; i<land.size(); i++){
            if(land[i][j] == 1){
                bfs(i, j, cnt, land);
                cnt++;
            }
        }
    }
    
    for(auto i : max_cnt)
        answer = max(answer, i);
    //문제유형 : bfs + 구현 + 해싱
    return answer;
}