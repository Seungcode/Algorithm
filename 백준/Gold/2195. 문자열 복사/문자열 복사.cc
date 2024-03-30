#include <iostream>
#include <string>

using namespace std;

//정답과 문자열을 담을 변수 선언
string S, P;
int answer = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //문자열 입력받기
    cin>>S>>P;


    //가장 적게 하려면 -> 해당 순서에서 가장 긴 문자열만큼 뽑아와야함
    for(int i = 0; i<P.length(); i++){
        int cnt = 0;
        answer++;
        for(int j = 0; j<S.length(); j++){
            //만약 문자열이 같다면
            if(P[i]==S[j]){
                int temp = 0;
                //다를 때까지 비교
                for(int z = j; z<S.length(); z++){
                    if(P[temp+i] == S[temp+j])
                        temp++;
                    else break;
                }
                cnt = max(cnt , temp);
            }
        }
        //가장 긴 문자열만큼 점프
        i += cnt -1;
    }

    //문제유형 : 그리디

    cout<<answer;
}