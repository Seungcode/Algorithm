#include <vector>
#include <iostream>
#include <map>
#include <queue>

using namespace std;

int N, M;
map<int, int> degree;
vector<int> arr[1001];
queue <int> q;
queue <int> answer;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;

    for(int i = 0; i<M; i++){
        int a;
        cin>>a;
        vector<int> temp(a);

        for(int j = 0; j<a; j++)
            cin>>temp[j];

        for(int j = 0; j<a; j++){
            for(int z = j+1; z<a; z++){
                arr[temp[j]].push_back(temp[z]);
                degree[temp[z]]++;
            }
        }

    }

    for(int i = 1; i<=N; i++){
        if(degree[i] == 0){
            q.push(i);
        }
    }

    for(int i = 1; i<=N; i++){
        if(q.empty()){
            cout<<0;
            return 0;
        }
        int now = q.front();
        answer.push(now);
        q.pop();
        for(auto j : arr[now]){
            if(--degree[j] == 0)
                q.push(j);
        }
    }

    while(!answer.empty()){
        cout<<answer.front()<<"\n";
        answer.pop();
    }
    //문제유형 : 위상정렬
    return 0;
}
