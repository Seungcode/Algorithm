 #include <iostream>

using namespace std;

int main() {
    int n, k = 1;
	cin >> n;
	for (int i = 2; i*i <= n; i++)
	{
		if (n%i == 0)
		{
			k = n / i;
			break;
		}
	}
	cout << n - k;
}
