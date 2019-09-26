#ifndef _SYMBOLTABLE_H
#define _SYMBOLTABLE_H
#include<iostream>
#include"node.hpp"
using std::cout;
template<typename key,typename value>
class symbol_table{
public:
    symbol_table()=default;
    symbol_table(const symbol_table<key,value>& ref);
    symbol_table& operator=(const symbol_table<key,value>& ref);
    ~symbol_table ()=default;
    void put(const key& key_name,const value& value_name);
    void delete_key(const key& key_name);
    value get(const key& key_name);
    bool contain(const key& key_name);
private:
     node<key,value>* root=0;
     int size=0;

};
template<typename key,typename value>
void symbol_table<key,value>::put (const key& key_name,const value& value_name) {
        if(root==nullptr){
            root = new node<key,value>(key_name,value_name,nullptr);
        }
        else {
            root->insert (key_name,value_name);
        }
}
template <typename key,typename value>
void symbol_table<key,value>::delete_key(const key& key_name){
    if(root=nullptr){
        return;
    }
    else if(key_name==root->get_key()){
        root=root->next;
    }
    else {
        root->delete_key(key_name,root);
    }
}



#endif