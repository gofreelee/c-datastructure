#include"BinaryTree.h"
int main(){
    int qq=12;
    int* tt=(int*)malloc(sizeof(int));
    *tt=13;
    delete tt;
    BinaryTree<int> a;
    BinaryTree<int> c(a);
    a.insert(12);
    a.insert(13);
    a.insert(14);
   // a.preorder();
    a.delete_node(13);
    a.preorder();
    BinaryTree<int>b (a);
   // BinaryTree<int>*c =&b;
   // c->preorder();
   // b.preorder();
}