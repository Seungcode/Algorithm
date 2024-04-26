#include <vector>
#include <iostream>
#include <map>

using namespace std;

int N, S;
vector<int> arr;
map <int, int> s;
long long int answer = 0;

//부분 수열의 합 구하기
void make_sum(int start, int end, int sum){
    if(start == end){
        if(end == N)
            answer += s[S-sum];
        else
            s[sum]++;
        return;
    }

    //더할 경우 아닐 경우 나누기
    make_sum(start+1, end, sum+arr[start]);
    make_sum(start+1, end, sum);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력받기
    cin >> N >> S;
    arr.resize(N);

    for(int i = 0; i<N; i++)
        cin>>arr[i];

    make_sum(0, N/2, 0);
    make_sum(N/2, N, 0);

    if(S==0)
        answer--;

    cout<<answer;

    //문제유형 : 중간에서 만나기
    return 0;
}
