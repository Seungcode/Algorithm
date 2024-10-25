#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<long long, long long> visited;

//다음 방 번호 지칭
long long find(long long n){
    if(visited[n] == 0) return n;
    return visited[n] = find(visited[n]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    
    for(auto i : room_number){
        long long room = find(i);
        answer.push_back(room);
        visited[room] = room + 1;
    }
    return answer;
}