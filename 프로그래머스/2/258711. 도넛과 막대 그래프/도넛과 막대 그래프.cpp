#include <string>
#include <vector>
#include <map>

using namespace std;

map<int, int> node_in;
map<int, int> node_out;


vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    int node = 0;
    
    for(auto i : edges){
        node = max(node, max(i[0], i[1]));
        node_out[i[0]]++;
        node_in[i[1]]++;
    }
    
    int s_node;
    
    for(int i = 1; i <= node; i++){
        if(node_in[i] == 0 && node_out[i] > 1){
            s_node = i;
            break;
        }
    }
    
    answer.push_back(s_node);
      
    for(int i = 0; i<3; i++) answer.push_back(0);
    
    for(int i = 1; i<=node; i++){
        if(node_in[i] >= 2 && node_out[i] >= 2) answer[3] ++;
        else if(node_in[i] > 0 && node_out[i] == 0) answer[2] ++;
    }
    
    answer[1] = node_out[s_node] - answer[2] - answer[3];
    
    return answer;
}