#include "symbol_table.hpp"
#include<iostream>
using namespace std;
int main(){
    symbol_table<int,int> test;
    test.put(1,13);
    test.put(3,33);
    test.put(4,23);
    symbol_table<int,int> adc=test;
    cout<<adc.get(3);   
    cout<<adc.size(); 
    cout<<adc.contain(4);
 
}