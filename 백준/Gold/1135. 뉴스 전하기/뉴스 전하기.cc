#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//인원 수를 담을 변수
int N;

//상사를 담을 백터
vector<vector<int>> arr;

//dfs 사용
int dfs(int n){
    int result = 0;
    
    //리프부터 시작해 깊이를 담아줌
    if(arr[n].size()==0)
        return 1;
    vector<int> arr_call;
    for(auto i : arr[n])
        arr_call.push_back(dfs(i));
    sort(arr_call.begin(), arr_call.end(), greater());
    
    //깊이가 깊은 순서대로 수행하며 시간을 더해준 후 가장 오래 걸리는 걸 기준으로 시간 초기화
    for(int i = 0; i<arr[n].size(); i++)
        result = max(result, arr_call[i] + i);
    
    //반환값 -> 상사가 전화거는거 포함하기 위해 1 더함
    return result+1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //인원 수
    cin>>N;

    arr.resize(N+1);

    //상사 입력 받기
    for(int i = 0; i<N; i++){
        int upper;
        cin>>upper;
        if(i!=0)
            arr[upper].push_back(i);
    }

    //민식이는 전화 걸 사람 없음 -> 1빼주기
    cout<<dfs(0)-1;

    //문제유형 : dfs + greedy
}