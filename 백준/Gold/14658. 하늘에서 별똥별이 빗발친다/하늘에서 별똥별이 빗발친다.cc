#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, L, K;
vector<pair<int, int>> arr;

void input() {
    cin>>N>>M>>L>>K;
    for(int i = 0; i<K; i++){
        int x, y;
        cin>>x>>y;
        arr.push_back({x, y});
    }
    sort(arr.begin(), arr.end());
}

void solution() {
    input();

    int answer = 0;

    for(int i = 0; i<K; i++){
        for(int j = 0; j<K; j++){
            int temp = 0;
            int nx = arr[i].first + L;
            int ny = arr[j].second + L;
            for(int r = 0; r<K; r++){
                if(arr[r].first <= nx
                && arr[r].first >= arr[i].first
                && arr[r].second <= ny
                && arr[r].second >= arr[j].second) temp++;
                if(arr[r].first > nx) break;
            }
            answer = max(answer, temp);
        }
    }

    cout<<K-answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}