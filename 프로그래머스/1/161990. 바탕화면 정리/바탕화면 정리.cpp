#include <string>
#include <vector>
#include <limits.h>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    //배열 초기화 -> 최소값 쓸 칸은 맥스 값으로(51으로 해도 상관 X), 최대값은 0으로!
    vector<int> answer = {INT_MAX, INT_MAX, 0, 0};
    
    //#나올 때 마다 값 업데이트
    for(int i = 0; i<wallpaper.size(); i++){
        for(int j = 0; j<wallpaper[0].size(); j++){
            if(wallpaper[i][j] == '#'){
                answer[0] = min(answer[0], i);
                answer[1] = min(answer[1], j);
                answer[2] = max(answer[2], i+1);
                answer[3] = max(answer[3], j+1);
            }
        }
    }
    
    //시간복잡도 O(N*M) -> 마지막 for문 -> 두 값의 최대가 50이니까 최대 반복해야 2500번! -> 시간복잡도 문제 X
    return answer;
}