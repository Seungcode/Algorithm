#include <iostream>
#include <vector>

using namespace std;

int N, answer = 0;
vector<int> arr[1000001];
bool visited[1000001] = {false, };
int adopter[1000001] = {0, };

void dfs(int now){
    for(auto i : arr[now]){
        if(!visited[i]) {
            visited[i] = true;
            adopter[i] = 1;
            dfs(i);
            if(adopter[i] == 1) adopter[i] = 0;
        }
    }

    for(auto i : arr[now]){
        if(adopter[i] == 0 && adopter[now]!=2){
            adopter[now] = 2;
            answer++;
            break;
        }
    }
}

int main() {
    cin >> N;

    if(N==1){
        cout<<1;
        exit(0);
    }

    for(int i = 1; i<N; i++){
        int a, b;
        cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    dfs(1);

    cout<<answer;
    return 0;
}