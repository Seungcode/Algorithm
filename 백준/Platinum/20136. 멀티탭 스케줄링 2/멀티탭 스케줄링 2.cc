#include <iostream>
#include <queue>

using namespace std;

int N, K, cnt = 0;
int arr[500001];
int idx[500001];
queue<int> pos[500001];

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

        if(idx[device] == 0) {
            if (cnt == N) {
                while (!pq.empty()) {
                    Info top = pq.top();
                    pq.pop();
                    if (idx[top.device] == 0) continue;
                    idx[top.device] = 0;
                    break;
                }
                answer++;
            }
            else cnt ++;
        }

        idx[device] = pos[arr[i]].empty() ? 500001 : pos[arr[i]].front();

        pq.push({idx[device], device});
    }

    cout << answer;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solution();
}
