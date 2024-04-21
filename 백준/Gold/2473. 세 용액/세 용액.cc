#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

//변수 설정
int N;
int start, last, middle;
long long int min_sum = 3000000001;
vector<long long int> arr;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력받기
    cin>>N;

    for(int i = 0; i<N; i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }

    //정렬
    sort(arr.begin(), arr.end());

    //투포인터 사용해서 값 찾기
    for(int s = 0; s<N-2; s++){
        int e = N-1;
        int temp = s+1;
        while(temp < e){
            long long int sum = arr[s]+arr[e]+arr[temp];
            if(abs(sum) < min_sum){
                min_sum = abs(sum);
                start = s;
                middle = temp;
                last = e;
            }
            if(sum < 0) temp ++;
            else e--;
        }
    }

    cout<<arr[start]<<" "<<arr[middle]<<" "<<arr[last];

    //문제유형 : 투포인터 + 이분탐색
}