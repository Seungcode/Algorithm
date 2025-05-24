#include <iostream>
#include <queue>

using namespace std;

struct Hw{
    int day;
    int score;

    bool operator<(Hw const & other) const {
        if(score == other.score) return day < other.day;
        return score < other.score;
    }
};

int N;
bool visited[1001] = {false, };
priority_queue<Hw> arr;

void input(){
    cin>>N;

    for(int i = 0; i < N; i++){
        int d, w;
        cin>>d>>w;

        arr.push({d, w});
    }
}

bool find(int n){
    for(int i = n; i > 0; i--){
        if(!visited[i]){
            visited[i] = true;
            return true;
        }
    }
    return false;
}

void solution() {
    input();

    int answer = 0;

    while(!arr.empty()){
        Hw now = arr.top();
        arr.pop();
        if(find(now.day))
            answer += now.score;
    }
    
    cout<<answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solution();
}
