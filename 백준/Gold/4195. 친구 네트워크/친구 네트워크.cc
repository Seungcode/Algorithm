#include <iostream>
#include <map>

using namespace std;

int N;
int cnt[200001];
int arr[200001];
map<string, int> idx;

int find(int a){
    if(arr[a] == a) return a;
    return arr[a] = find(arr[a]);
}

void union_arr(int a, int  b){
    a = find(a);
    b = find(b);
    if(a!=b) {
        arr[b] = arr[a];
        cnt[a] += cnt[b];
    }
    cout<<cnt[a]<<"\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 0; i<N; i++){
        int a;
        cin>>a;

        idx.clear();

        int now = 1;

        for(int j = 0; j<a; j++){
            string first, second;
            cin>>first>>second;
            if(idx[first]==0){
                idx[first] = now;
                arr[now] = now;
                cnt[now] = 1;
                now++;
            }
            if(idx[second]==0){
                idx[second] = now;
                arr[now] = now;
                cnt[now] = 1;
                now++;
            }
            union_arr(idx[first], idx[second]);
        }
    }

    //문제유형 : 분리집합 + 해시
}
