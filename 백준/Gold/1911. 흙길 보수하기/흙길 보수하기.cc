#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, L;
int answer = 0;
vector <pair<int, int>> arr;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>L;

    for(int i = 0; i<N; i++){
        int start, end;
        cin>>start>>end;
        arr.push_back({start, end});
    }

    sort(arr.begin(), arr.end());

    int now = -1;
    for(int i = 0; i<N; i++){
        if(now < arr[i].first)
            now = arr[i].first;
        while(now < arr[i].second){
            answer++;
            now+=L;
        }
    }

    cout<<answer;
    
    //문제유형 : greedy

    return 0;
}
