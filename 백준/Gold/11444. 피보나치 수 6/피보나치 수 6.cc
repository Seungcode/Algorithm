#include <iostream>
#include <map>
using namespace std;

map<long long, long long> f;

long long fibo(long long n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 1;

    //이미 값이 있다면 -> 이미 구한 값
    if (f.count(n) > 0) return f[n];

    //짝수일 때 연산
    if (n % 2 == 0) {
        long long m = n / 2;
        long long temp1 = fibo(m - 1);
        long long temp2 = fibo(m);
        f[n] = ((2LL * temp1 + temp2) * temp2) % 1000000007;
        return f[n];
    }

    //홀수 일 때 연산
    long long m = (n + 1) / 2;
    long long temp1 = fibo(m);
    long long temp2 = fibo(m - 1);
    f[n] = (temp1 * temp1 + temp2 * temp2) % 1000000007;
    return f[n];
}

int main(void) {
    long long n;

    cin >> n;
    cout << fibo(n);

    return 0;

    //문제유형 : 분할 정복
}