#include <string>
#include <vector>

using namespace std;

int dx[3] = {-1, -1, 0};
int dy[3] = {0, -1, -1};
char arr[30][30];
char temp[30][30];

//정사각형의 모양으로 같은 블럭이 있는지 확인
bool check(int x, int y){
    for(int i = 0; i<3; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx < 0 || ny < 0) return false;
        if(arr[x][y] != arr[nx][ny] || arr[nx][ny] == ' ') return false;
    }
    
    return true;
}

//임시 배열 초기화
void initArr(){
    for(int i = 0; i<30; i++){
        for(int j = 0; j<30; j++) {
            temp[i][j] = arr[i][j];
        }
    }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    //배열에 저장 -> 편의성을 위함
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j <board[0].length(); j++) {
            arr[i][j] = board[i][j];
        }
    }
    
    while(true){
        //temp초기화
        initArr();
        
        //더 사라질 블럭이 있는지 확인하기 위함
        bool flag = true;
        
        //사라질 블럭 여부 확인
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                //블럭이 사라진다면
                if(check(i, j)){
                    flag = false;
                    temp[i][j] = ' ';
                    for(int z = 0; z<3; z++) temp[i+dx[z]][j+dy[z]] = ' ';
                }
            }
        }
        
        //사라질 블럭이 없다면
        if(flag) break;
        
        //블럭 내려주기
        for(int i = m-1; i>=0; i--){
            for(int j = n-1; j>=0; j--){
                //기존 배열 초기화
                arr[i][j] = ' ';
                //빈칸이 아닐경우 -> 그대로
                if(temp[i][j] != ' ') {
                    arr[i][j] = temp[i][j];
                    temp[i][j] = ' ';
                }
                //빈칸일 경우
                else{
                    int temp_i = i-1;
                    //위에서 가장 가까운 블럭 내리기
                    while(temp_i >= 0){
                        if(temp[temp_i][j] != ' ') {
                            arr[i][j] = temp[temp_i][j];
                            temp[temp_i][j] = ' ';
                            break;
                        }
                        temp_i --;
                    }
                }
            }
        }
        
    }
    
    //사라진 블럭 수 확인
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++) if(arr[i][j] == ' ') answer++;
    }
    
    return answer;
}