template<typename key,typename value>
class symboltable;
template<typename key,typename value>
     class node{
         friend class symboltable<key,value>;
         public:
            node()=default;
            node(const key& key_name,const value& value_name,node<key,value>* next_node){
                _key=key_name;
                _value = value_name;
                next=next_node;
            }
            node (const node<key,value>& ref);
            node& operator= (const node<key,value>& ref);
            bool insert (const key& key_name,const value& value_name){
                node<key,value>* tmp=this->next;
                while(tmp!=nullptr){
                    if(tmp->_key == key_name){
                        tmp->_value=value_name;
                        std::cout<<"该键已存在,现已更新";
                        return true;
                    }
                    tmp=tmp->next;
                }
                node<key,value> new_node(key_name,value_name);
                *tmp=new_node;
                return true;
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
         private:
            key _key;
            value _value;
            node* next=0;
     };