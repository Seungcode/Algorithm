#include <iostream>
#include <queue>

using namespace std;

long long int answer = 0;
int N, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>M;
    for(int j = 0; j<M; j++) {

        answer = 0;

        cin >> N;

        priority_queue<long long int, vector<long long int>, greater<>> arr;

        for (int i = 0; i < N; i++) {
            int a;
            cin >> a;
            arr.push(a);
        }

        while (arr.size() > 1) {
            long long int temp = 0;
            answer += arr.top();
            temp += arr.top();
            arr.pop();
            answer += arr.top();
            temp += arr.top();
            arr.pop();
            arr.push(temp);
        }
        cout << answer<<'\n';
    }

   return 0;

    //문제유형 : priority queue
}
