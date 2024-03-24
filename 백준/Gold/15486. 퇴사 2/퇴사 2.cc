#include <iostream>

using namespace std;

int arr[1501002] = {0, };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //날짜수 입력받기
    int a;
    cin>>a;

    for(int i = 1; i<=a; i++){
        //날짜수와 비용 입력받기
        int b, c;
        cin>>b>>c;
        //그 의뢰를 수락했을 경우 -> 수락한 날과 비교
        arr[i+b] = max(arr[i+b], arr[i] + c);
        //그 의뢰를 수락하지 않을 경우 -> 다음 날과 비교
        arr[i+1] = max(arr[i+1], arr[i]);
    }
    cout<<arr[a+1];
}
