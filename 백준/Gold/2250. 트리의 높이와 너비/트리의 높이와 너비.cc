#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int N, answer = 0, level = 10001;
vector<int> y[10001];
int idx = 1;
unordered_map<int, int> root;

struct Node{
    int left;
    int right;
}node[10001] ;

void input() {
    cin>>N;

    for(int i = 0; i<N; i++){
        int a, b, c;
        cin>>a>>b>>c;
        root[b]++;
        root[c]++;
        node[a].left = b;
        node[a].right = c;
    }
}

void set(int a, int lev) {
    if(node[a].left == -1 && node[a].right == -1){
        y[lev].push_back(idx);
        idx++;
        return;
    }

    if(node[a].left != -1){
        set(node[a].left, lev + 1);
    }

    y[lev].push_back(idx);
    idx++;

    if(node[a].right != -1){
        set(node[a].right, lev + 1);
    }
}

void find(){
    for(int i = 1; i<=N; i++){
        if(y[i].empty()) break;
        sort(y[i].begin(), y[i].end());
        int temp = y[i].back() - y[i].front() + 1;
        if(temp > answer){
            answer = temp;
            level = i;
        }
    }
}
void solution() {
    input();
    for(int i = 1; i<=N; i++){
        if(root[i] == 0){
            set(i, 1);
            break;
        }
    }
    find();
    cout<<level<<" "<<answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}
