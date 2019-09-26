#include "symbol_table.hpp"
#include<iostream>
using namespace std;
int main(){
    symbol_table<int,int> test;
    test.put(1,13);
    cout<<test.get(1);   
    cout<<test.size(); 
 
}