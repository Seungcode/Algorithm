#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>

#define INF 987654321
using namespace std;

long long int gcd, lcm;
long long int resultA = 0, resultB = 0;

void input(){
    cin >> gcd >> lcm;
}

int getGCD(int a, int b){
    if(b == 0)  return a;
    return getGCD(b, a % b);
}

void solve(){
    long long int divide = lcm / gcd;

    for(int i = 1; i <= sqrt(divide); i++){
        if(divide % i == 0){ 
            long long int a = i, b = divide/i;

            if(getGCD(a, b) == 1){
                resultA = a;
                resultB = b;
            }
        }
    }

    cout << resultA * gcd << ' ' << resultB * gcd;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    solve();

    return 0;
}