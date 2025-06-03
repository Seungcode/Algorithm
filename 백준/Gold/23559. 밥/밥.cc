#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct menu{
    int expensive;
    int cheap;

    bool operator <(menu const & other) const {
        if((expensive - cheap) == (other.expensive - other.cheap)) return expensive > other.expensive;
        return (expensive - cheap) > (other.expensive - other.cheap);
    }
};
int N, X;
long long answer = 0;
vector<menu> arr;

void input(){
    cin>>N>>X;
    for(int i = 0; i<N; i++){
        int a, b;
        cin>>a>>b;
        arr.push_back({a, b});
    }

    sort(arr.begin(), arr.end());
}

void solution() {
    input();

    for(int i = 0; i<N; i++){
        if(X - 5000 - 1000*(N - 1 - i) >= 0){
            answer += max(arr[i].expensive, arr[i].cheap);
            if(arr[i].expensive - arr[i].cheap >= 0) {
                X -= 5000;
            }
            else X -= 1000;
        }
        else{
            X -= 1000;
            answer += arr[i].cheap;
        }
    }
    cout<<answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solution();
}
