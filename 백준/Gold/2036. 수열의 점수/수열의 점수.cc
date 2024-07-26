#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
long long int answer = 0;
vector<long long> arr;
bool flag = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;
    for(int i = 0; i<N; i++){
        long long a;
        cin>>a;
        arr.push_back(a);
    }

    sort(arr.begin(), arr.end());

    while(!arr.empty()){
        if(arr.back() <= 0 && flag == 0){
            sort(arr.begin(), arr.end(), greater<int>());
            flag = 1;
        }
        if(arr.size() == 1) {
            answer += arr.back();
            arr.pop_back();
        }
        else{
            long long temp = arr.back();
            arr.pop_back();
            if(temp * arr.back() > temp + arr.back()){
                answer += temp * arr.back();
                arr.pop_back();
            }
            else answer += temp;
        }
    }

    cout<<answer;
}