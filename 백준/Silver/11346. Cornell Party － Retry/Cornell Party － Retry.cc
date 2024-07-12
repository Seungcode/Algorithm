#include <iostream>
using namespace std;

#include <set>
int main(){
    int T; cin >> T;
    for(int t = 1; t <= T; t++){
        int N, M; cin >> N >> M;
        set<string> set_;
        for(int i=0; i<N; i++){
            string tmp; cin >> tmp;
            set_.insert(tmp);
        }
        for(int i =0; i <M; i++){
            string tmp; cin >> tmp;
            set_.insert(tmp);
        }
        cout << set_.size() <<'\n';
    }
    
    return 0;
}