#include <iostream>
#include <map>
using namespace std;

int T, N, M;
int answer;
map<string, int> arr;

void input(){
    cin>>T;
}

void init(){
    arr.clear();
    answer = 0;
}

void solution() {
    input();

    for(int i = 0; i<T; i++){
        init();
        cin>>N>>M;
        cout<<"#"<<i+1<<" ";
        for(int j = 0; j<N; j++){
            string a;
            cin>>a;
            arr[a] ++;
        }

        for(int j = 0; j<M; j++){
            string a;
            cin>>a;
            if(arr[a] != 0) answer++;
        }

        cout<<answer<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solution();
}