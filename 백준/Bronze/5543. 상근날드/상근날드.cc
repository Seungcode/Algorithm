#include <iostream>

using namespace std;

int main(){
    int min_cost_burger = 3000;
    int min_cost_drink = 3000;
    
    for(int i = 0; i < 3; i++){
        int a;
        cin>>a;
        min_cost_burger = min(min_cost_burger, a);
    }
    
    for(int i = 0; i < 2; i++){
        int a;
        cin>>a;
        min_cost_drink = min(min_cost_drink, a);
    }
    
    cout<<min_cost_drink + min_cost_burger - 50;
}