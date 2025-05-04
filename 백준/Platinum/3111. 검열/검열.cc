#include <iostream>
#include <vector>

using namespace std;

string A, B, reverseA;
int start, fin, flag = 1;
string front, behind;

void input() {
    cin>>A>>B;

    for(int i = A.length() - 1; i >= 0; i--) reverseA += A[i];

    start = -1;
    fin = B.length();
}

void findFront(){
    while(start != fin){
        if(!front.empty() && front.size() >= A.size() && front.back() == A.back()){
            string temp = front.substr(front.size() - A.size(), A.size());
            if(temp == A){
                for(int i = 0; i<temp.size(); i++) front.pop_back();
                flag = 2;
                return;
            }
        }
        start ++;
        if(start == fin) break;
        front.push_back(B[start]);
    }
    flag = 3;
}

void findBehind(){
    while(true){
        if(!behind.empty() && behind.size() >= A.size() && behind.back() == reverseA.back()){
            string temp = behind.substr(behind.size() - A.size(), A.size());
            if(temp == reverseA){
                for(int i = 0; i<temp.size(); i++) behind.pop_back();
                flag = 1;
                return;
            }
        }
        fin --;
        if(start == fin) break;
        behind.push_back(B[fin]);
    }
    flag = 3;
}

void solution() {
    input();

    while(flag != 3){
        if(flag == 1) findFront();
        else if(flag == 2)findBehind();
    }

    while(!behind.empty()){

        front.push_back(behind.back());
        behind.pop_back();
        if(!front.empty() && front.size() >= A.size() && front.back() == A.back()){
            string temp = front.substr(front.size() - A.size(), A.size());
            if(temp == A){
                for(int i = 0; i<temp.size(); i++) front.pop_back();
            }
        }

    }

    cout<<front;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
    return 0;
}
