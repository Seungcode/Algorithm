#include <iostream>

using namespace std;

int H, W;
int arr[501];

void input(){
    cin>>H>>W;
    for(int i = 0; i<W; i++) cin>>arr[i];
}
void solution() {
    input();

    int answer = 0;

    for(int i = 1; i<=H; i++) {
        bool flag = false;
        int temp = 0;
        for(int j = 0; j<W; j++){
            if(arr[j] >= i) {
                if(!flag){
                    flag = true;
                }
                else {
                    answer += temp;
                    temp = 0;
                }
            }
            else {
                if(flag) temp++;
            }
        }
    }

    cout<<answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}