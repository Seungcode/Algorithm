#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    //인덱스로 접근하기 위해 배열 초기화
    vector<int> answer;
    answer.resize(id_list.size());
    
    //배열 0으로 초기화
    int arr[1001][1001] = {0, };
    
    //인덱싱 번호 매길 map과 받은 횟수를 저장할 map 정의
    map <string, int> index;
    map <string, int> receive;

    //인덱싱 번호 저장
    for(int i = 0; i<id_list.size(); i++)
        index[id_list[i]] = i;
    
    //받은 횟수 정리 -> 만약 그 사람이 여러번 보냈을 경우 -> 제외
    for(auto i : report){
        int flag = 0;
        string receiver = "";
        string sender = "";
        for(int j = 0; j<i.length(); j++){
            if(i[j] == ' ')
                flag = 1;
            else if(flag == 1)
                receiver += i[j];
            else
                sender += i[j];
        }
        if(arr[index[receiver]][index[sender]] == 0)
            receive[receiver] ++;
        arr[index[receiver]][index[sender]] = 1;
    }

    //만일 한 사람이 지정 횟수 이상으로 신고를 받았을 경우 -> 보낸 사람 대상으로 메일 수 증가
    for(auto i : id_list){
        if(receive[i]>=k){
            for(int j = 0; j<id_list.size(); j++){
                if(arr[index[i]][j])
                    answer[j]++;
            }
        }
    }
    
    //문제 유형 : 구현
    
    return answer;
}