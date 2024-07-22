#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int N, sum = 0;
    cin >> N;

    vector<int> v1(N), v2(N);

    for (int i = 0; i < N; ++i)
        cin >> v1[i];

    for (int i = 0; i < N; ++i)
        cin >> v2[i];

    sort(v1.begin(), v1.end());
    sort(v2.rbegin(), v2.rend());

    for (int i = 0; i < N; ++i)
        sum += v1[i] * v2[i];

    cout << sum;
}
