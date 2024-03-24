#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//데이터와 정렬 기준의 인덱스 값을 가져온다 -> 문자를 숫자로
int ex = 0;
int sort_ = 0;

//해당 칸을 기준으로 정렬할 것이기 때문에 이에 따른 cmp함수를 선언함
bool cmp(vector<int> a, vector<int> b){
    return a[sort_] < b[sort_];
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    //배열값 지정
    string data_col[4] = {"code", "date", "maximum", "remain"};
    for(int i = 0; i<4; i++){
        if(ext == data_col[i]){
            ex = i;
        }
        if(sort_by == data_col[i]){
            sort_ = i;
        }
    }
    //기준보다 작으면 -> 배열에 추가
    for(auto i : data){
        if(i[ex]<val_ext){
            answer.push_back(i);
        }
    }
    //정렬
    sort(answer.begin(), answer.end(), cmp);
    return answer;
}