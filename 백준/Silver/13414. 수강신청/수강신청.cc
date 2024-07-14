#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int N, M;
map<string, int> order;
vector <pair<int, string>> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>M>>N;

    for(int i = 1; i<=N; i++) {
        string student;
        cin>>student;
        order[student] = i;
    }

    for(auto i : order) q.push_back({i.second, i.first});

    sort(q.begin(), q.end());

    for(int i = 0; i<M && i<q.size(); i++){
        cout<<q[i].second<<"\n";
    }
}
