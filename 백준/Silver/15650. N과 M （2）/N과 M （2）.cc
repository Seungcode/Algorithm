#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[9] = {0, };
bool visited[9] = {false, };
void back_track(int a,int b){
    if(b==m){
        for(int i =0; i<m; i++)
            printf("%d ", arr[i]);
        printf("\n");
        return;
    }
    else{
        for(int i = a; i<=n; i++){
            if(!visited[i]) {
                arr[b]= i;
                visited[i] = true;
                back_track(i, b + 1);
                visited[i] = false;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    back_track(1, 0);
    return 0;
}