#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

int N, K;
int arr[500001];
queue<int> pos[500001];
int idx[500001];
unordered_set<int> plugged;

struct Info {
    int next_idx;
    int device;

    bool operator<(const Info& o) const {
        return next_idx < o.next_idx;
    }
};

void input(){
    cin >> N >> K;
    for (int i = 0; i < K; ++i) {
        cin >> arr[i];
        pos[arr[i]].push(i);
    }
}

priority_queue<Info> pq;

void solution() {
    input();

    int answer = 0;

    for (int i = 0; i < K; ++i) {
        int device = arr[i];
        pos[arr[i]].pop();
        idx[device] = pos[arr[i]].empty() ? 500001 : pos[arr[i]].front();

        if(!plugged.count(device)) {
            if (plugged.size() == N) {
                while (!pq.empty()) {
                    Info top = pq.top();
                    pq.pop();
                    if (plugged.count(top.device) == 0) continue;
                    plugged.erase(top.device);
                    break;
                }
                answer++;
            }
            plugged.insert(device);
        }

        pq.push({idx[device], device});
    }

    cout << answer;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solution();
}
