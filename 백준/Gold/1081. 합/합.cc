#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, M;
long long answer = 0;
long long sum[11] = {0, 45, 900, 13500, 180000, 2250000, 27000000, 315000000,3600000000, 40500000000};

void input(){
    cin>>N>>M;

    if(N != 0) N--;
}

int findSum(int a){
    int temp = 0;
    for(int i = 0; i<=a; i++){
        temp += i;
    }
    return temp;
}

long long findCnt(int a) {
    long long temp = 0;
    long long count = 0;

    vector<int> num;

    if(a == 0)
        return 0;
    
    while(a > 0){
        num.push_back(a%10);
        a = a/10;
    }

    count = num[0];
    temp += findSum(num[0]);

    for(int i = 1; i < num.size(); i++) {
        temp += (sum[i] + 1) * (num[i]) + findSum(num[i]-1)*pow(10, i);
        temp += num[i]*count;
        count += num[i]*pow(10, i);
    }

    return temp;
}

void solution() {
    input();

    answer += findCnt(M);
    answer -= findCnt(N);

    cout<<answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}