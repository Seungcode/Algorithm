#include <iostream>
#include <queue>

using namespace std;

int answer = 0;
int N;
priority_queue<int, vector<int>, greater<>> arr;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;

   for(int i = 0; i<N; i++){
       int a;
       cin>>a;
       arr.push(a);
   }

   while(arr.size() > 1){
       int temp = 0;
       answer += arr.top();
       temp += arr.top();
       arr.pop();
       answer += arr.top();
       temp += arr.top();
       arr.pop();
       arr.push(temp);

   }

   cout<<answer;

   return 0;

    //문제유형 : priority queue
}
