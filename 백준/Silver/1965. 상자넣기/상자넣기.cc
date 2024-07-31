#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int DP[1001];
    int n, inp, ret = 0;
    vector<int> v;

    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        scanf("%d", &inp);
        v.push_back(inp);
        DP[i] = 0;
    }

    for(int i=0;i<n;i++) {
        DP[i] = 1;
        for(int j=0;j<i;j++) { 
            if(v[j] < v[i]) { 
                DP[i] = max(DP[i], DP[j] + 1); 
            }
        }
        ret = max(ret, DP[i]); 
    }

    printf("%d", ret);

    return 0;
}