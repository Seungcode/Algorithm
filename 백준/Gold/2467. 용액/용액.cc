#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<long long int> arr;
long long int N, le, ri;
int an_le, an_ri;

//이분 탐색
void find(){
    an_le = 0;
    an_ri = N-1;
    ri = N-1;
    le = 0;
    long long int temp = abs(arr[ri] + arr[le]);
    while(le<ri){
        if(abs(arr[ri] + arr[le]) < temp){
            temp = abs(arr[ri] + arr[le]);
            an_le = le;
            an_ri = ri;
        }
        if(arr[ri] + arr[le] > 0) ri -= 1;
        else if(arr[ri] + arr[le] < 0) le += 1;
        else return;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력받기
    cin>>N;

    for(int i = 0; i < N; i++){
        long long int a;
        cin>>a;
        arr.push_back(a);
    }

    find();

    cout<<arr[an_le]<<" "<<arr[an_ri];
    //문제유형 : 이분 탐색
}