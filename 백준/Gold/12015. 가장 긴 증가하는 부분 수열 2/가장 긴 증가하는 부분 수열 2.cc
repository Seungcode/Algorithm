#include <vector>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    vector<int> lis;
    lis.push_back(arr[0]);

    for (int i = 1; i < N; ++i) {
        if (arr[i] > lis.back()) {
            lis.push_back(arr[i]);
        } else {
            // 이진 탐색으로 삽입 위치를 찾음
            int left = 0, right = lis.size() - 1;
            while (left < right) {
                int mid = (left + right) / 2;
                if (lis[mid] < arr[i]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            // 해당 위치에 값 할당
            lis[right] = arr[i];
        }
    }

    cout << lis.size();

    return 0;
}
