#include <iostream>
#include <vector>

using namespace std;

int N;
int arr[200];
vector<int> n_move;

//압력받기
void input(){
    cin>>N;

    for(int i = 0; i<N; i++) cin>>arr[i];

}

void solution(){
    for(int i = 0; i<N; i++){

        if(n_move.empty() || n_move.back() < arr[i]) n_move.push_back(arr[i]);
        else {
            for (int j = 0; j < n_move.size(); j++) {
                if (n_move[j] > arr[i]){
                    n_move[j] = arr[i];
                    break;
                }
            }
        }
    }

    cout<<N - n_move.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    solution();

    return 0;
}