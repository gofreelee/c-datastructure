#ifndef _SYMBOLTABLE_H
#define _SYMBOLTABLE_H
#include<iostream>
#include"node.hpp"
using std::cout;
template<typename key,typename value>
class symbol_table{
public:
    symbol_table(){
        this->_size=0;
    };
    symbol_table(const symbol_table<key,value>& ref);
    symbol_table& operator=(const symbol_table<key,value>& ref);
    ~symbol_table ();
    void put(const key& key_name,const value& value_name);
    void delete_key(const key& key_name);
    value get(const key& key_name);
    bool contain(const key& key_name);
    int size()const{
        return this->_size;
    };
private:
     node<key,value>* root=0;
     int _size;

};
template<typename key,typename value>
void symbol_table<key,value>::put (const key& key_name,const value& value_name) {
        if(root==nullptr){
            root = new node<key,value>(key_name,value_name,nullptr);
            _size++;
        }
        else {
            root->insert(key_name,value_name,_size);
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

template <typename key,typename value>
value symbol_table<key,value>::get(const key& key_name){
    return root->get(key_name);
}

template <typename key,typename value>
symbol_table<key,value>::~symbol_table(){
    root->clear();
}



#endif