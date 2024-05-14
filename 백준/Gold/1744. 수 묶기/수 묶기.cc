#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int answer = 0;
vector <int> p;
vector <int> m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;

    for(int i = 0; i <N; i++){
        int a;
        cin>>a;
        if(a==1) answer++;
        else if(a>0) p.push_back(a);
        else m.push_back(a);
    }

    sort(p.begin(), p.end(), greater());
    sort(m.begin(), m.end());

    for(int i = 0; i<p.size(); i++){
        if(i==p.size()-1) answer += p[i];
        else{
            answer += p[i]*p[i+1];
            i++;
        }
    }

    for(int i = 0; i<m.size(); i++){
        if(m[i] == 0 && (m.size()-i)%2==0) continue;
        if(i==m.size()-1) answer += m[i];
        else{
            answer += m[i]*m[i+1];
            i++;
        }
    }

    cout<<answer;

    return 0;

    //문제유형 :greedy
}
