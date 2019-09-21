#ifndef _BTNARYTREE_H
#define _BTNARYTREE_H
#include "BTnode.h"
#include<iostream>
using std::cout;
template <typename type_val>
class BinaryTree{
public:
    BinaryTree();
    BinaryTree(const BinaryTree& );
    BinaryTree& operator=(const BinaryTree&);
    ~BinaryTree();//要释放内存
    bool empty(){return root==0;}
    void insert(const type_val& elem);
    void delete_node(const type_val& elem);
    void delete_node(const BTnode<type_val>& node);
    void delete_root();
    //前序遍历
    void preorder();
    BTnode<type_val>& find_elem(const type_val& elem);
    static BTnode<type_val>& find_left_leaf( BTnode<type_val>* node);
private:
    BTnode<type_val>* root;
    void copy(const BTnode<type_val>* tar,const BTnode<type_val>* src);
    void clear();

};
template<typename type_val>
void BinaryTree<type_val>::clear(){
    if(root==0){}
    else root->clear_node();
}
template<typename type_val>
BinaryTree<type_val>::~BinaryTree(){
    clear();
}
template<typename type_val>
BinaryTree<type_val>::BinaryTree(const BinaryTree<type_val>& src){
    if(src.root==0){
        root=nullptr;
    }
    else{
        root=new BTnode<type_val>();
        root->copy(src.root);
    }
}
template <typename type_val>
inline BinaryTree<type_val>::BinaryTree(){
    root=nullptr;
}
template<typename type_val>
inline BinaryTree<type_val>& BinaryTree<type_val>::operator=(const BinaryTree& src){
    if(&src!=this){
    clear();
    copy(root,src);
    }
    return *this;
}
template <typename type_val>
inline void BinaryTree<type_val>::insert(const type_val& elem){
    if(root==nullptr){
        root=new BTnode<type_val>(elem);
    }
    else{
        root->insert_val(elem);
    }
}
template <typename type_val>
void BinaryTree<type_val>::delete_node(const type_val& elem){
    if(this->root==0){
        cout<<"empty binarytree";
        return;
    }
    else if(elem==this->root->_val){
        delete_root();
    }
    else {
        root->delete_val(elem,root);
    }
}
template <typename type_val>
void BinaryTree<type_val>::delete_node(const BTnode<type_val>& elem){
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
template <typename type_val>
BTnode<type_val>& BinaryTree<type_val>::find_elem(const type_val& elem){
    BTnode<type_val>& tmp=*this->root;
    if(tmp==nullptr)
    return nullptr;
    else if(tmp._val==elem)return tmp;
    else if(tmp._val<elem){
        tmp=*tmp.right;
        
    }
}
template <typename type_val>
void BinaryTree<type_val>::preorder(){
    BTnode<type_val>::preorder(root);
}
template <typename type_val>
void BinaryTree<type_val>::delete_root(){
    if(root==0)return;
    if(root->left==0&&root->right==0){
        delete root;
        return;
    }
    BTnode<type_val>* tmp=root;
    if(root->left==0){
        root=root->right;
        delete tmp;
    }
    else if(root->right==0){
        root=root->left;
        delete tmp;
    }
    else {
        BTnode<type_val>* route_node=root->right;
        while(route_node->left!=nullptr){
            route_node=route_node->left;
        }
        route_node->left=root->left;
        root=root->right;
        delete tmp;
    }
}
#endif
