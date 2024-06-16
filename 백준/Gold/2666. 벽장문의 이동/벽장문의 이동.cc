#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int n = 0, k = 0;
int open1, open2;
int arr[21] = { 0, };
int dp[21][21][21];

int solved(int o1, int o2,int cnt) {

	if (cnt == k + 1)
		return 0;

	int &ret = dp[o1][o2][cnt];
	if (ret != -1)
		return ret;
	ret = 0;
	ret = min(abs(arr[cnt] - o1) + solved(arr[cnt], o2, cnt + 1), abs(arr[cnt] - o2) + solved(o1, arr[cnt], cnt + 1));
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	memset(dp, -1, sizeof(dp));

	cin >> n;
	cin >> open1 >> open2;
	cin >> k;
	for (int i = 1; i <= k; i++)
		cin >> arr[i];

	cout<<solved(open1, open2, 1)<<endl;


	return 0;
}