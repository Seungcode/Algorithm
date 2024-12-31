#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
long long int dis = 2000000001;
vector<long long int> arr;
int answer[2] = {0, };

void solution(){
    sort(arr.begin(), arr.end());

    int first = 0;
    int last = N-1;

    while(first<last){
        if(abs(arr[first] + arr[last]) < abs(dis)){
            dis = arr[first] + arr[last];
            answer[0] = arr[first];
            answer[1] = arr[last];
        }

        if(arr[first] + arr[last] < 0)
            first++;
        else if(arr[first] + arr[last] > 0)
            last--;
        else break;
    }

    for(auto i : answer)
        cout<<i<<" ";
}

//입력받기
void input(){
    cin>>N;

    for(int i = 0; i<N; i++) {
        long long int a;
        cin>>a;
        arr.push_back(a);
    }

    solution();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();

    return 0;
}