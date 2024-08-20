#include <iostream>
#include <algorithm>

using namespace std;

int N, M, K;
int Y = 0;
int arr[51][51] = {0, };
int temp[51][51] = {0, };

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int dy_1[4] = {1, 0, -1, 0};
int dx_1[4] = {0, -1, 0, 1};

int dy_2[4] = {1, 0, -1, 0};
int dx_2[4] = {0, 1, 0, -1};

void make_arr(){

    for(int i = 0; i<N; i++) {
        for(int j = 0; j<M; j++) temp[i][j] = 0;
    }

    temp[Y][0] = -1;
    temp[Y+1][0] = -1;

    //미세먼지 확산
    for(int i = 0; i<N; i++) {
        for(int j = 0; j<M; j++) {
            if(arr[i][j] == -1 || arr[i][j] == 0) continue;
            int now = arr[i][j]/5;
            for(int z = 0; z<4; z++){
                int nx = i + dx[z];
                int ny = j + dy[z];
                if(nx<0 || ny<0 || nx>=N || ny>=M || arr[nx][ny] == -1) continue;
                temp[nx][ny] += now;
                arr[i][j] -= now;
            }
            temp[i][j] += arr[i][j];
        }
    }

    for(int i = 0; i<N; i++) {
        for(int j = 0; j<M; j++) arr[i][j] = 0;
    }

    arr[Y][0] = -1;
    arr[Y+1][0] = -1;

    //공기청정기 순회
    int nx = Y;
    int ny = 0;

    for(int i = 0; i<4; i++) {

        while (true) {
            if(nx + dx_1[i]<0 || ny + dy_1[i]<0 || nx + dx_1[i]>=N || ny + dy_1[i]>=M || arr[nx + dx_1[i]][ny + dy_1[i]] == -1) break;
            if(temp[nx][ny] == -1) arr[nx+dx_1[i]][ny+dy_1[i]] = 0;
            else arr[nx+dx_1[i]][ny+dy_1[i]] = temp[nx][ny];
            nx = nx + dx_1[i];
            ny = ny + dy_1[i];
        }
    }

    nx = Y+1;
    ny = 0;

    for(int i = 0; i<4; i++) {
        while (true) {
            if(nx + dx_2[i]<0 || ny + dy_2[i]<0 || nx + dx_2[i]>=N || ny + dy_2[i]>=M || arr[nx + dx_2[i]][ny + dy_2[i]] == -1) break;
            if(temp[nx][ny] == -1) arr[nx+dx_2[i]][ny+dy_2[i]] = 0;
            else arr[nx+dx_2[i]][ny+dy_2[i]] = temp[nx][ny];
            nx = nx + dx_2[i];
            ny = ny + dy_2[i];
        }
    }

    for(int i = 1; i<Y; i++){
        for(int j = 1; j<M-1; j++) arr[i][j] = temp[i][j];
    }

    for(int i = Y+2; i<N-1; i++){
        for(int j = 1; j<M-1; j++) arr[i][j] = temp[i][j];
    }

}
int main() {
    cin>>N>>M>>K;

    for(int i = 0; i<N; i++) {
        for(int j = 0; j<M; j++) cin>>arr[i][j];
        if(Y==0&&arr[i][0] == -1) Y = i;
    }

    for(int i = 0; i<K; i++){
        make_arr();
    }

    int now = 0;
    for(int i = 0; i<N; i++) {
        for(int j = 0; j<M; j++) now += arr[i][j];
    }

    cout<<now + 2;
}