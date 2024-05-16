#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[1000001] = {0, };

int parent(int a){
    if(a == arr[a]) return a;
    return arr[a] = parent(arr[a]);
}

bool find(int a, int b){
    return parent(arr[a]) == parent(arr[b]);
}

void union_sum(int a, int b){
    a = parent(a);
    b = parent(b);
    if(a==b) return;
    arr[b] = a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;

    for(int i = 1; i <= N; i++)
        arr[i] = i;


    for(int i = 0; i<M; i++){
        int a, b, c;
        cin>>a>>b>>c;
        if(a==1){
            if(find(b, c)) cout<<"YES"<<'\n';
            else cout<<"NO"<<'\n';
        }
        else{
            union_sum(b, c);
        }
    }

    return 0;

    //문제유형 : unoin-find
}
