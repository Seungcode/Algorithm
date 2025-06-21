#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int N;
unsigned long long int arr[100];
vector<unsigned long long> v[100];

void input(){
    cin>>N;

    for(int i = 0; i<N; i++){
        cin>>arr[i];
    }
}

void solution() {
    input();

    for (int i = 0; i < N; ++i) {
        int po = 0;
        unsigned long long p = 3;
        while (arr[i] % p == 0) {
            ++po;
            p *= 3;
        }
        v[po].push_back(arr[i]);
    }
    int maxpo = 0;
    for (int i = 0; i < 100; ++i) {
        if (!v[i].empty()) maxpo = i;
        sort(v[i].begin(), v[i].end());
    }
    for (int i = maxpo; i >= 0; --i) {
        for (auto a : v[i]) {
            cout << a << " ";
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solution();
}
