#include <iostream>

using namespace std;

int N, M;
int arr[301] = {0, };
int maxNum;
int low = 0, high, middle;

void input() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        low = max(low, arr[i]);
        arr[i] += arr[i-1];
    }
}

bool find(int size) {
    int idx = 0;
    int final = 0;

    for(int i = 1; i <= N; i++){
        if(arr[i] - arr[final] == size) {
            idx++;
            final = i;
        }
        else if(arr[i] - arr[final] > size){
            idx++;
            final = i - 1;
        }
    }

    if(final != N) idx ++;
    return idx <= M;
}

void makeGroup(int size){
    int final = 0;

    for (int i = 1; i <= N; i++) {
        if (arr[i] - arr[final] > size) {
            cout << i - 1 - final << " ";
            final = i - 1;
            M--;
        }
        else if (arr[i] - arr[final] == size) {
            cout << i - final << " ";
            final = i;
            M--;
        }

        if(M == 1){
            cout<<N - final;
            return;
        }
        
        if (M == N - final) break;
    }

    for (int i = final + 1; i <= N; i++) {
        cout << "1 ";
    }
}


void solution() {
    input();

    high = arr[N];

    while(low < high) {
        middle = (low + high)/2;
        if(!find(middle))
            low = middle + 1;
        else high = middle;
    }

    cout<<low<<"\n";
    makeGroup(low);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}
