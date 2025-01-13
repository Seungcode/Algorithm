#include <algorithm>
#include <iostream>
using namespace std;

int answer = 0;
int arr[6] = {0, };

void solution() {
    answer += arr[5];

    answer += arr[4];
    arr[0] -= arr[4] * 11;
    if (arr[0] < 0) arr[0] = 0;

    answer += arr[3];
    arr[1] -= arr[3] * 5;
    if (arr[1] < 0) {
        arr[0] += arr[1] * 4;
        arr[1] = 0;
        if (arr[0] < 0) arr[0] = 0;
    }

    answer += arr[2] / 4;
    if (arr[2] % 4 != 0) {
        answer++;
        if (arr[2] % 4 == 1) {
            arr[1] -= 5;
            arr[0] -= 7;
        }
        else if (arr[2] % 4 == 2) {
            arr[1] -= 3;
            arr[0] -= 6;
        }
        else if (arr[2] % 4 == 3) {
            arr[1] -= 1;
            arr[0] -= 5;
        }
        if (arr[1] < 0) {
            arr[0] += arr[1] * 4;
            arr[1] = 0;
        }
        if (arr[0] < 0) arr[0] = 0;
    }

    answer += arr[1] / 9;
    if (arr[1] % 9 != 0) {
        answer ++;
        arr[0] -= ((9 - arr[1] % 9)*4);
    }
    if (arr[0] < 0) arr[0] = 0;

    answer += arr[0] / 36;
    if (arr[0] % 36 != 0) answer++;

}

void input() {

    for (int i = 0; i<6; i++)
        cin>>arr[i];

    solution();

    cout<<answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();

    return 0;
}