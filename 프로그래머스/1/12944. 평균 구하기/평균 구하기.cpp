#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    int temp = 0;
    for(auto i : arr)
        temp += i;
    answer = (double)temp/arr.size();
    return answer;
}