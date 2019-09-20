#ifndef _BTNODE_H
#define _BTNODE_H
#include<iostream>
using std::cout;
template <typename elemType>
class BinaryTree;
template <typename typeval>
class BTnode{
    friend class BinaryTree<typeval>;
public:
    BTnode()=default;
    BTnode(const typeval& );
    void insertVal(const typeval& elem);
    void deleteVal(const typeval& elem,BTnode<typeval>*& prev);
    static void preorder(BTnode<typeval>* node);
    static BTnode<typeval>* findLeftLeaf(BTnode<typeval>* route);
private:
     typeval _val;
     int cnt;//节点值的重复次数
     BTnode* left;
     BTnode* right;
     void clear_node(){
         if(left!=0)left->clear_node();
         if(right!=0)right->clear_node();
         delete this;
     }
     void copy(BTnode<typeval>* src){
         _val=src->_val;
         if(src->left!=0&&left==0)left=new BTnode<typeval>();
         if(src->right!=0&&right==0)right=new BTnode<typeval>();
         if(src->left!=0)left->copy(src->left);
         if(src->right!=0)right->copy(src->right);
     }
};
template <typename valType>
inline BTnode<valType>::BTnode(const valType& val):_val(val){
    cnt=0;
    left=right=0;
}
template <typename valType>
BTnode<valType>* BTnode<valType>::findLeftLeaf(BTnode<valType>* route){
    if(route->left==nullptr){
        return route;
    }
    else{
        BTnode<valType>* tmp=route;
        while(tmp->left!=nullptr){
            tmp=tmp->left;
        }
        return tmp;
    }
} 
//节点插入函数
template <typename valType>
inline void BTnode<valType>::insertVal(const valType& elem){
         if(elem==_val) return ;
         else if(_val<elem){
             if(right!=0)
             right->insertVal(elem);
             else 
             right=new BTnode<valType>(elem);
         }
         else if(_val>elem){
             if(left!=0)
             left->insertVal(elem);
             else 
             left=new BTnode<valType>(elem);
         }
         return ;
}
template <typename valType>
void BTnode<valType>::preorder(BTnode<valType>* node){
     if(node==0)return;
     cout<<node->_val<<" ";
     preorder(node->left);
     preorder(node->right);
}
template <typename valType>
void BTnode<valType>::deleteVal(const valType& val,BTnode<valType>*& prev){
    if(val<_val){
       left->deleteVal(val,left);
    }
    else if(val>_val){
       right->deleteVal(val,right);
    }
    else {
      if(right!=nullptr){
         BTnode<valType>* tmp=findLeftLeaf(right);
         tmp->left=this->left;
         prev=right;
      }
      else prev=left;
    }
} 
#endif