#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, cost;
pair<int, int> coin[100];
bool possible[50001] = {false, };

void init() {
    for(int i = 0; i<N; i++) coin[i] = {0, 0};
    memset(possible, false, sizeof(possible));
}

void input(){
    cin>>N;
    cost = 0;
    for(int i = 0; i<N; i++) {
        cin>>coin[i].first>>coin[i].second;
        cost += coin[i].first * coin[i].second;
    }
}

void canDivide() {
    int target = cost / 2;
    possible[0] = true;

    for(int i = 0; i < N; i++) {
        int value = coin[i].first;
        int count = coin[i].second;

        for(int j = target; j >= 0; j--) {
            if(possible[j]) {
                for(int k = 1; k <= count; k++) {
                    if(j + value * k > target) break;
                    possible[j + value * k] = true;
                }
            }
        }
    }
}

void solution() {
    for(int i = 0; i<3; i++) {
        init();
        input();

        if(cost % 2 != 0) {
            cout << "0\n";
            continue;
        }

        canDivide();

        cout<<possible[cost/2]<<"\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}
