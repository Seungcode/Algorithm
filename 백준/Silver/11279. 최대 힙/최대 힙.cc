#include <iostream>
#include <queue>

using namespace std;

//배열크기를 받아 줄 변수
int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;
    
    //우선순위 큐를 사용해서 구현
    priority_queue<int> arr;

    //0일 때와 아닐 때를 나눠 명령어 수행
    for(int i = 0; i<N; i++) {
        int a;
        cin>>a;
        
        //0일 때
        if(a==0){
            if(arr.empty())
                cout<<0<<"\n";
            else{
                cout<<arr.top()<<"\n";
                arr.pop();
            }
        }
        
        //아닐 때
        else
            arr.push(a);
    }
    
    //문제 유형 : 구현 (우선순위 큐)

}