#ifndef _BTNARYTREE_H
#define _BTNARYTREE_H
#include "BTnode.h"
#include<iostream>
using std::cout;
template <typename typeval>
class BinaryTree{
    public:
    BinaryTree();
    BinaryTree(const BinaryTree& );
    BinaryTree& operator=(const BinaryTree&);
    ~BinaryTree();//要释放内存
    bool empty(){return root==0;}
    void insert(const typeval& elem);
    void delete_node(const typeval& elem);
    void delete_node(const BTnode<typeval>& node);
    void delete_root();
    //前序遍历
    void preorder();
    BTnode<typeval>& find_elem(const typeval& elem);
    static BTnode<typeval>& find_left_leaf( BTnode<typeval>* node);
    private:
     BTnode<typeval>* root;
     void copy(const BTnode<typeval>* tar,const BTnode<typeval>* src);
     void clear();

};
template<typename typeVal>
void BinaryTree<typeVal>::clear(){
    if(root==0)delete root;
    else root->clear_node();
}
template<typename typeVal>
BinaryTree<typeVal>::~BinaryTree(){
    clear();
}
template<typename typeVal>
BinaryTree<typeVal>::BinaryTree(const BinaryTree<typeVal>& src){
    if(src.root==0){
        root=nullptr;
    }
    else{
        root=new BTnode<typeVal>();
        root->copy(src.root);
    }
}
template <typename typeval>
inline BinaryTree<typeval>::BinaryTree(){
    root=nullptr;
}
template<typename typeval>
inline BinaryTree<typeval>& BinaryTree<typeval>::operator=(const BinaryTree& src){
    if(&src!=this){
    clear();
    copy(root,src);
    }
    return *this;
}
template <typename typeVal>
inline void BinaryTree<typeVal>::insert(const typeVal& elem){
    if(root==nullptr){
        root=new BTnode<typeVal>(elem);
    }
    else{
        root->insertVal(elem);
    }
}
template <typename typeVal>
void BinaryTree<typeVal>::delete_node(const typeVal& elem){
    if(this->root==0){
        cout<<"empty binarytree";
        return;
    }
    else if(elem==this->root->_val){
        delete_root();
    }
    else {
        root->deleteVal(elem,root);
    }
}
template <typename typeVal>
void BinaryTree<typeVal>::delete_node(const BTnode<typeVal>& elem){
    if (&elem==this->root)
    {
        delete_root();
    }
    else 
    {
        find_left_leaf(*(elem->right)).left=elem.left;
        elem=elem->right;
    }
}
template <typename typeVal>
BTnode<typeVal>& BinaryTree<typeVal>::find_elem(const typeVal& elem){
         BTnode<typeVal>& tmp=*this->root;
         if(tmp==nullptr)
         return nullptr;
         else if(tmp._val==elem)return tmp;
         else if(tmp._val<elem){
             tmp=*tmp.right;
             
         }
}
template <typename typeVal>
void BinaryTree<typeVal>::preorder(){
    BTnode<typeVal>::preorder(root);
}
template <typename typeVal>
void BinaryTree<typeVal>::delete_root(){
    if(root==0)return;
    if(root->left==0&&root->right==0){
        delete root;
        return;
    }
    BTnode<typeVal>* tmp=root;
    if(root->left==0){
        root=root->right;
        delete tmp;
    }
    else if(root->right==0){
        root=root->left;
        delete tmp;
    }
    else {
        BTnode<typeVal>* route_node=root->right;
        while(route_node->left!=nullptr){
            route_node=route_node->left;
        }
        route_node->left=root->left;
        root=root->right;
        delete tmp;
    }
}
#endif
