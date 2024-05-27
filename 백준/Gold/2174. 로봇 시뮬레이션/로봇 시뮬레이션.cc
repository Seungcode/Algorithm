#include <iostream>
#include <map>
using namespace std;

int A, B;
int N, M;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int robot[101][101] = {0, };
map <int, pair<pair<int, int>, int>> arr;
map <char, int> f;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>A>>B;
    cin>>N>>M;

    f['W'] = 0;
    f['N'] = 1;
    f['E'] = 2;
    f['S'] = 3;

    for(int i = 0; i<N; i++){
        int x, y;
        char forward;
        cin>>x>>y>>forward;
        arr[i+1] = {{x, y}, f[forward]};
        robot[x][y] = i+1;
    }

    for(int i = 0; i<M; i++){
        int idx, cnt;
        char forward;
        cin>>idx>>forward>>cnt;
        if(forward == 'F') {
            robot[arr[idx].first.first][arr[idx].first.second] = 0;
            for(int j = 0; j<cnt; j++){
                arr[idx].first.first += dx[arr[idx].second];
                arr[idx].first.second += dy[arr[idx].second];
                if (arr[idx].first.first > A || arr[idx].first.first <= 0 || arr[idx].first.second > B ||
                    arr[idx].first.second <= 0) {
                    printf("Robot %d crashes into the wall", idx);
                    exit(0);
                }
                else if(robot[arr[idx].first.first][arr[idx].first.second]!=0){
                    printf("Robot %d crashes into robot %d", idx, robot[arr[idx].first.first][arr[idx].first.second]);
                    exit(0);
                }
            }
        }
        else if(forward == 'L') {
            for (int j = 0; j < cnt; j++)
                arr[idx].second = (arr[idx].second - 1 + 4) % 4;
        }
        else {
            for (int j = 0; j < cnt; j++)
                arr[idx].second = (arr[idx].second + 1) % 4;
        }
    }

    cout<<"OK";

    return 0;

    //문제유형 : 구현
}
