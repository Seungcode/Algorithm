#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct s 
{
    int location;
    int priority;
};

int solution(vector<int> priorities, int location) 
{
    queue<s> q;
    for(int i = 0; i < priorities.size(); ++i) { q.push({i, priorities[i]}); }
    sort(begin(priorities), end(priorities), [](int a, int b) { return a > b; });

    int answer = 0;
    while(true)
    {
        s pr = q.front(); q.pop();

        if(priorities[answer] == pr.priority)
        {
            ++answer;
            if(pr.location == location) { break; }
            continue;
        }

        q.push(pr);
    }

    return answer;
}