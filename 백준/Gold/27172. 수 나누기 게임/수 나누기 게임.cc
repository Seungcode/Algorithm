#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

//변수 설정
int N;
int arr[100001] = {0, };
int prime[1000001] = {0, };
map <int, int> idx;
vector<int> num;


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력받기
    cin>>N;

    //수 입력받고 인덱스 저장하기
    for(int i = 1; i<=N; i++){
        int a;
        cin>>a;
        idx[a] = i;
        prime[a] = 1;
        num.push_back(a);
    }

    //작은 수부터 정렬
    sort(num.begin(), num.end());


    //작은 수부터
    for(auto i : num){
        for(int j = i*2; j<=num[num.size()-1]; j+=i){
            //1일 경우 -> 승자와 패자 발생
            if(prime[j]==1){
                arr[idx[i]-1]++;
                arr[idx[j]-1]--;
            }
        }
    }

    //출력
   for(int i = 0; i<N; i++)
        cout<<arr[i]<<" ";

    //문제유형 : 수학
}