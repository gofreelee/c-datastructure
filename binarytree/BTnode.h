#ifndef _BTNODE_H
#define _BTNODE_H
#include<iostream>
using std::cout;
template <typename elem_type>
class BinaryTree;
template <typename type_val>
class BTnode{
    friend class BinaryTree<type_val>;
public:
    BTnode()=default;
    BTnode(const type_val&src);
    void insert_val(const type_val& elem);
    void delete_val(const type_val& elem,BTnode<type_val>*& prev);
    static void preorder(BTnode<type_val>* node);
    static BTnode<type_val>* findLeftLeaf(BTnode<type_val>* route);
private:
    type_val _val;
    int cnt;//节点值的重复次数
    BTnode* left;
    BTnode* right;
    void clear_node(){
        if(left!=0)left->clear_node();
        if(right!=0)right->clear_node();
        delete this;
    }
    void copy(BTnode<type_val>* src){
        _val=src->_val;
        if(src->left!=0&&left==0)left=new BTnode<type_val>();
        if(src->right!=0&&right==0)right=new BTnode<type_val>();
        if(src->left!=0)left->copy(src->left);
        if(src->right!=0)right->copy(src->right);
    }
};
template <typename type_val>
inline BTnode<type_val>::BTnode(const type_val& val):_val(val){
    cnt=0;
    left=right=0;
}
template <typename type_val>
BTnode<type_val>* BTnode<type_val>::findLeftLeaf(BTnode<type_val>* route){
    if(route->left==nullptr){
        return route;
    }
    else{
        BTnode<type_val>* tmp=route;
        while(tmp->left!=nullptr){
            tmp=tmp->left;
        }
        return tmp;
    }
} 
//节点插入函数
template <typename type_val>
inline void BTnode<type_val>::insert_val(const type_val& elem){
    if(elem==_val) return ;
    else if(_val<elem){
        if(right!=0)
        right->insert_val(elem);
        else 
        right=new BTnode<type_val>(elem);
    }
    else if(_val>elem){
        if(left!=0)
        left->insert_val(elem);
        else 
        left=new BTnode<type_val>(elem);
    }
    return ;
}
template <typename type_val>
void BTnode<type_val>::preorder(BTnode<type_val>* node){
    if(node==0)return;
    cout<<node->_val<<" ";
    preorder(node->left);
    preorder(node->right);
}
template <typename type_val>
void BTnode<type_val>::delete_val(const type_val& val,BTnode<type_val>*& prev){
    if(val<_val){
       left->delete_val(val,left);
    }
    else if(val>_val){
       right->delete_val(val,right);
    }
    else {
      if(right!=nullptr){
         BTnode<type_val>* tmp=findLeftLeaf(right);
         tmp->left=this->left;
         prev=right;
      }
      else prev=left;
    }
} 
#endif