#include <iostream>
#include <vector>

using namespace std;

int N, M;
int answer = 0;
vector <int> arr;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;

    for(int i = 0; i <N; i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }

    int start = 0;
    int end = 0;
    int cnt = 0;

    while(start < N) {
        while (end < N) {
            if (arr[end] % 2 == 0) {
                end++;
            }
            else {
                if (cnt < M) {
                    cnt++;
                    end++;
                }
                else break;
            }
        }
        answer = max(answer, end - start - cnt);
        if(arr[start]%2!=0) cnt--;
        start ++;
    }

    cout<<answer;

    return 0;

    //문제유형 :two-pointer
}
