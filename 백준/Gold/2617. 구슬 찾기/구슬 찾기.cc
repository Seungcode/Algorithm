#include <iostream>

using namespace std;

int N, M, answer = 0;
int arr[100][100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N>>M;

    for(int i = 0; i<M; i++){
        int start, end;
        cin>>start>>end;

        arr[end][start] = -1;
        arr[start][end] = 1;
    }

    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            for(int z = 1; z<=N; z++){
                if(arr[j][i] == -1 && arr[i][z] == -1) arr[j][z] = -1;
                else if(arr[j][i] == 1 && arr[i][z] == 1) arr[j][z] = 1;
            }
        }
    }

    for(int i = 1; i<=N; i++){

        int temp_p = 0;
        int temp_m = 0;
        for(int j = 1; j<=N; j++){
            if(arr[i][j] == 1) temp_p++;
            else if(arr[i][j] == -1) temp_m++;
        }

        if(temp_p > N/2 || temp_m > N/2) answer++;
    }

    cout<<answer;
    return 0;
}