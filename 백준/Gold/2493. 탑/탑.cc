#include <iostream>
#include <stack>
#include <math.h>

using namespace std;

int N;
int result[500001] = {0, };
stack<int> arr;
stack<pair<int, int>> q;

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

   while(!arr.empty()){
       while (!q.empty()){
           if(q.top().second <= arr.top()) {
               result[q.top().first] = arr.size();
               q.pop();
           }
           else
               break;
       }

       q.push({arr.size()-1, arr.top()});
       arr.pop();
   }

   for(int i = 0; i<N; i++)
       cout<<result[i]<<" ";

   return 0;

    //문제유형 : stack
}
