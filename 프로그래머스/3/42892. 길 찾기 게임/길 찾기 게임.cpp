#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

//노드 구조체
struct Node{
    int left;
    int right;
};

//이외 변수 선언
vector<int> temp_pre;
vector<int> temp_back;
Node arr[100001];
map<int, int> num;

//y기준 정렬을 위함
bool comp(vector<int> a, vector<int> b){
    return a[1] > b[1];
}

//노드 삽입
void push(int before, int now){
    if(now > before){
        if(arr[before].right == -1){
            arr[before].right = now;
        }
        else{
            push(arr[before].right, now);
        }
    }
    
    else{        
        if(arr[before].left == -1){
            arr[before].left = now;
        }
        else{
            push(arr[before].left, now);
        }
    }
}

//전위순회
void pre(int now){
    temp_pre.push_back(num[now]);
    if(arr[now].left != -1) pre(arr[now].left);
    if(arr[now].right != -1) pre(arr[now].right);
}

//후위순회
void back(int now){
    if(arr[now].left != -1) back(arr[now].left);
    if(arr[now].right != -1) back(arr[now].right);
    temp_back.push_back(num[now]);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    
    //노드 넘버 인덱싱
    for(int i = 0; i<nodeinfo.size(); i++) num[nodeinfo[i][0]] = i+1;
    
    //y기준 정렬
    sort(nodeinfo.begin(), nodeinfo.end(), comp);
    
    //루트노드 셋팅
    arr[nodeinfo[0][0]] = {-1, -1};
    int root = nodeinfo[0][0];
    
    //그래프 생성
    for(int i = 1; i<nodeinfo.size(); i++){
        arr[nodeinfo[i][0]] = {-1, -1};
        push(root, nodeinfo[i][0]);
    }
    
    //정답 생성
    pre(root);
    back(root);
    
    answer.push_back(temp_pre);
    answer.push_back(temp_back);
    
    return answer;
}