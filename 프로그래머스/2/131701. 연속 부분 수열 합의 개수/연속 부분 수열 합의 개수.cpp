#include <string>
#include <vector>
#include <map>

using namespace std;

//배열 선언
int mk_sum[1001][2001] = {0, };
map <int, int> cnt;

int solution(vector<int> elements) {
    int answer = 0;
    
    //하나로 이뤄진 경우 카운트
    for(int i = 0; i<elements.size(); i++){
        if(cnt[elements[i]] == 0){
            answer++;
        }
        mk_sum[1][i] = elements[i];
        mk_sum[1][i+elements.size()] = elements[i];
        cnt[elements[i]]++;
    }
    
    //연속 부분 수열 합의 개수 확인하기
    for(int i = 2; i<=elements.size(); i++){
        for(int j = i-1; j<elements.size()*2; j++){
            if(cnt[mk_sum[i-1][j-1] + elements[j%elements.size()]] == 0){
                answer++;
            }
            mk_sum[i][j] = mk_sum[i-1][j-1] + elements[j%elements.size()];
            cnt[mk_sum[i][j]]++;
        }
    }
    
    //문제유형 : 누적합
    
    return answer;
}