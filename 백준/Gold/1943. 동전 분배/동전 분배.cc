#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, cost;
pair<int, int> coin[100];
int dp[50001]; // 최대 cost의 절반은 25000까지 가능

void init() {
    for(int i = 0; i<N; i++) coin[i] = {0, 0};
}

void input(){
    cin>>N;
    cost = 0;
    for(int i = 0; i<N; i++) {
        cin>>coin[i].first>>coin[i].second;
        cost += coin[i].first * coin[i].second;
    }
}

bool canDivide() {
    int target = cost / 2;
    vector<bool> possible(target + 1, false);
    possible[0] = true;

    for(int i = 0; i < N; i++) {
        int value = coin[i].first;
        int count = coin[i].second;

        // 다중 동전 처리: 거꾸로 순회하며 count만큼 사용
        for(int j = target; j >= 0; j--) {
            if(possible[j]) {
                for(int k = 1; k <= count; k++) {
                    if(j + value * k > target) break;
                    possible[j + value * k] = true;
                }
            }
        }
    }

    return possible[target];
}

void solution() {
    for(int i = 0; i<3; i++) {
        init();
        input();

        if(cost % 2 != 0) {
            cout << "0\n";
            continue;
        }

        cout << (canDivide() ? "1" : "0") << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}
