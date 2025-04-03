#include <iostream>
#include <algorithm>
using namespace std;

int N;
string dp[101] = {};
string arr[8];

string findMax(int a){
    string temp;

    if(a%2 != 0){
        temp += '7';
        a -= 3;
    }

    while(a>0){
        temp += '1';
        a -= 2;
    }

    return temp;
}

string findMin(string a, string b){
    if(a.length() < b.length()) return a;
    else if(a.length() > b.length()) return b;

    if(a==b) return a;

    int idx = 0;
    while(true){
        if(a[idx] < b[idx]) return a;
        else if(a[idx] > b[idx]) return b;
        idx++;
    }
}

void input() {
    cin>>N;

    dp[2] = "1";
    dp[3] = "7";
    dp[4] = "4";
    dp[5] = "2";
    dp[6] = "6";
    dp[7] = "8";

    arr[2] = "1";
    arr[3] = "7";
    arr[4] = "4";
    arr[5] = "2";
    arr[6] = "0";
    arr[7] = "8";

    for(int i = 8; i <=100; i++){
        for(int j = 2; j <= 7; j++){
            if(i-j < 2) continue;
            string minimum = dp[i-j] + arr[j];
            if(minimum.length() <= dp[i].length() || dp[i].empty()) {
                sort(minimum.begin(), minimum.end());
                if (minimum.back() == '0') {
                    minimum[0] = '6';
                }
                else if (minimum[0] == '0') {
                    int idx = 0;
                    while (minimum[idx] == '0') {
                        idx++;
                    }
                    minimum[0] = minimum[idx];
                    minimum[idx] = '0';
                }
                if(dp[i].empty()) dp[i] = minimum;
                else dp[i] = findMin(minimum, dp[i]);
            }
        }
    }
}


void solution() {
    input();

    for(int i = 0 ; i<N; i++) {
        int a;
        cin>>a;

        cout<<dp[a]<<" "<< findMax(a)<<"\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}