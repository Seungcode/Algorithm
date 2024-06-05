#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int answer = 0;
vector<vector<int>> arr;
vector<vector<bool>> visited;
int dx[8] = {1, -1, 0, 0, -1, 1, 1, -1};
int dy[8] = {0, 0, 1, -1, -1, 1, -1, 1};

void bfs(int i, int j) {
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = true;
    while (!q.empty()) {
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();
        for (int z = 0; z < 8; z++) {
            int x = nx + dx[z];
            int y = ny + dy[z];
            if (x < 0 || y < 0 || x >= N || y >= M) continue;
            if (arr[x][y] <= arr[nx][ny] && !visited[x][y]) {
                visited[x][y] = true;
                q.push({x, y});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    arr.assign(N, vector<int>(M, 0));
    visited.assign(N, vector<bool>(M, false));
    priority_queue<pair<int, pair<int, int>>> temp;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] != 0) temp.push({arr[i][j], {i, j}});
        }
    }

    while (!temp.empty()) {
        int x = temp.top().second.first;
        int y = temp.top().second.second;
        if (!visited[x][y]) {
            answer++;
            bfs(x, y);
        }
        temp.pop();
    }

    cout << answer;

    return 0;
}
