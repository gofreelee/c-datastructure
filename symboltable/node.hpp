#ifndef _NODE_H
#define _NODE_H

template<typename key,typename value>
class symbol_table;
template<typename key,typename value>
class node{
    friend class symbol_table<key,value>;
public:
    node()=default;
    node(const key& key_name,const value& value_name,node<key,value>* next_node){
        _key=key_name;
        _value = value_name;
        next=next_node;
    }
    node (const node<key,value>& ref);
    bool find(const key& key_name)const;
    node& operator= (const node<key,value>& ref);
    ~node() = default;
    int insert (const key& key_name,const value& value_name,int size){
        node<key,value>* tmp=this;
        while(tmp->next!=nullptr){
            if(tmp->_key == key_name){
                tmp->_value=value_name;
                std::cout<<"该键已存在,现已更新";
                return size;
            }
            tmp=tmp->next;
        }
        tmp->next=new node<key,value> (key_name,value_name,nullptr);
        return size+1;
    }
    void delete_key (const key& key_name,node<key,value>*& prev){
        if(_key!=key_name){
            next->delete_ley(key_name,next);
        }
        prev->next=this->next;
        delete this;
    }
    key get_key()const{
        return _key;
    }
    value get(const key& key_name)const;
private:
    void clear();
    static void copy(node<key,value>* src,node<key,value>*& des);
    key _key;
    value _value;
    node* next=0;
};

template <typename key,typename value>
node<key,value>& node<key,value>::operator=(const node<key,value>& ref){
    this->_key=ref._key;
    this->_value=ref._value;
    this->next=ref.next;
}

template <typename key,typename value>
value node<key,value>::get(const key& key_name)const{
          if(_key==key_name){
              return _value;
          }
          next->get(key_name);
}

template <typename key,typename value>
void node<key,value>::clear(){
    if(next!=nullptr){
        next->clear();
    }
    delete this;
}

template <typename key,typename value>
void node<key,value>::copy(node<key,value>* src,node<key,value>*& des){
    if(des==nullptr&&src==nullptr)return;
    else if(des==nullptr){
        des=new node(src->_key,src->_value,nullptr);
    }
    else {
        des->_key=src->_key;
        des->_value=src->_value;
    }
    copy(src->next,des->next);
}

template <typename key,typename value>
node<key,value>::node (const node<key,value>& ref) {
    _key=ref._key;
    _value=ref._value;
}
template <typename key,typename value>
bool node<key,value>::find(const key& key_name)const{
    if(_key==key_name)return true;
    node<key,value>* tmp=next;
    while(tmp!=nullptr){
        if(tmp->_key==key_name){
            return true;
        }
        tmp=tmp->next;
    }
    return false;
}
#endif