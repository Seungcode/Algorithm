#include <iostream>
#include <queue>
#include <math.h>

using namespace std;

int N;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> arr;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;

   for(int i = 0; i<N; i++){
       int a, b;
       cin>>a>>b;
       arr.push({a, b});
   }

   int result = abs(arr.top().second - arr.top().first);
   int back = arr.top().second;
   int start = arr.top().first;
   arr.pop();

   while (!arr.empty()){
       if(arr.top().first >= start && arr.top().second <= back){
           arr.pop();
           continue;
       }
       else if(arr.top().first >= back){
           start = arr.top().first;
           back = arr.top().second;
           result += abs(back - start);
       }
       else{
           result += abs(arr.top().second - back);
           back = arr.top().second;
       }
       arr.pop();
    }

   cout<<result;
   return 0;

    //문제유형 : greedy
}
