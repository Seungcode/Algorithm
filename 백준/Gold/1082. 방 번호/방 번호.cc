#include <iostream>
#include <vector>

using namespace std;

//번효표 수와 금액 입력 받기
int N, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //번호표 수
    cin>>N;

    //금액을 입력받기 위한 벡터
    vector<int> arr;
    arr.resize(N);

    //금액 입력 받기
    for(int i = 0; i<N; i++){
        cin>>arr[i];
    }

    //예산 받기
    cin>>M;

    //금액에 따른 번호 저장 -> 최대 길이가 50자까지 -> string으로 저장
    vector<string> arr_money;
    arr_money.resize(M+1, "");

    //최대 번호 구하기
    for(int i = 1; i<=M; i++){
        for(int j = 0; j<N; j++){
            if(i-arr[j] >= 0){
                //새 문자열 생성
                string temp = arr_money[i-arr[j]] + to_string(j);
                
                //시작할 때 0 제거
                while(temp[0]=='0' && temp.length() > 1){
                    temp = temp.substr(1, temp.length()-1);
                }
                
                //길이가 다르면 -> 길이가 더 긴거 저장
                if(arr_money[i].length() != temp.length())
                    arr_money[i] = arr_money[i].length() > temp.length() ? arr_money[i] : temp;
                //길이가 같으면 -> 사전순으로 더 큰 값 저장
                else
                    arr_money[i] = arr_money[i] > temp ? arr_money[i] : temp;
            }
        }
    }
    
    //문제유형 : 다이나믹 프로그래밍 
    
    cout<<arr_money[M];
}