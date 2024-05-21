#include <iostream>

using namespace std;

long long int x1, x2, x3;
long long int y, y2, y3;

int ccw(long long int a,long long int b,long long int c,long long int d,long long int e,long long int f){
    long long int answer = 0;
    answer += a*d + c*f + e*b;
    answer -= (b*c + d*e + f*a);
    if(answer > 0) return 1;
    else if(answer == 0) return 0;
    else return -1;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>x1>>y>>x2>>y2>>x3>>y3;

    cout<<ccw(x1, y, x2, y2, x3, y3);

    return 0;

    //문제유형 : 기하학
}
