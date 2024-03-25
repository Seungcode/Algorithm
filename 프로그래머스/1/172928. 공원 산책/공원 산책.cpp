#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    //시작점 찾기
    for(int i = 0; i<park.size(); i++){
        for(int j = 0; j<park[i].length(); j++){
            if(park[i][j]=='S'){
                answer.push_back(i);
                answer.push_back(j);
            }
        }        
    }
    
    //정해진 대로 수행 -> 한 칸씩 해야하는 이유는? -> 중간에 X를 만나는 경우에도 다시 원점으로 돌아와야하기때문에
    for(auto i : routes){
        int cnt = i[2] - '0';
        int temp_y = answer[0];
        int temp_x = answer[1];
        while(cnt>0){
            if(i[0]=='E'){
                answer[1]++;
                if(answer[1] >= park[0].size()){
                    answer[1] = temp_x;
                    break;
                }
                if(park[answer[0]][answer[1]]=='X'){
                    answer[1] = temp_x;
                    break;
                }
            }
            else if(i[0]=='W'){
                answer[1]--;
                if(answer[1] < 0){
                    answer[1] = temp_x;
                    break;
                }
                if(park[answer[0]][answer[1]]=='X'){
                    answer[1] = temp_x;
                    break;
                }
            }
            else if(i[0]=='N'){
                answer[0]--;
                if(answer[0] < 0 ){
                    answer[0] = temp_y;
                    break;
                }
                if(park[answer[0]][answer[1]]=='X'){
                    answer[0] = temp_y;
                    break;
                }
            }
            else if(i[0]=='S'){
                answer[0]++;
                if(answer[0] >= park.size()){
                    answer[0] = temp_y;
                    break;
                }
                if(park[answer[0]][answer[1]]=='X'){
                    answer[0] = temp_y;
                    break;
                }
            }
            cnt--;
        }
    }
    return answer;
}