
#ifndef _HEAP_H
#define _HEAP_H
#include<stdlib.h>
#include<iostream>
using std::cout;
template <typename value>
class heap{    
public:
   typedef value* pointer;
   typedef value& reference;
   heap();
   heap(int max);
   heap(const heap<value>& src);
   heap( value *array,int num,bool(*comp)(const reference,const reference));
   ~heap();
   heap& operator=(const heap<value>& src);
   int delete_most();
   value get_index(int index)const;
   bool is_empty();
   value get_most()const;
   int size()const;
   void translate(value *array,int num,bool(*comp)(const reference,const reference));
   void insert(const reference ref);
   void print();
private:
   value *_array=0;
   int _max;
   int _cnt;
   bool (*cmp)(const reference a,const reference b)=0;
};
//默认构造函数
template <typename value>
heap<value>::heap(){
    _max=8;
    _cnt=0;
    _array=(pointer)malloc(_max*sizeof(reference));
}
template <typename value>
heap<value>::heap(int max){
    _max=max;
    _cnt=0;
    _array=(pointer)malloc(_max*sizeof(reference));
}
template <typename value>
heap<value>::heap( value *array,int num,bool(*comp)(const reference,const reference)){
    _max=num;
    _array=(pointer)malloc(sizeof(value)*_max);
    _cnt=0;
    cmp=comp;
    for(int i=0;i<num;i++){
        insert(array[i]);
    }
}
template <typename value>
heap<value>::heap(const heap<value>& src){
    _max=src._max;
    if(_array!=0)delete _array;
    _array=(pointer)malloc(_max*sizeof(value));
    cmp=src.cmp;
    for(int i=0;i<src._cnt;i++){
        _array[i]=src.get_index(i);
    }
    _cnt=src._cnt;
}
template <typename value>
heap<value>::~heap(){
    if(_array!=0){
        delete _array;
    }
}
template <typename value>
heap<value>& heap<value>::operator=(const heap<value>& src){
     _max=src._max;
    if(_array!=0)delete _array;
    _array=(pointer)malloc(_max*sizeof(value));
    cmp=src.cmp;
    for(int i=0;i<src._cnt;i++){
        _array[i]=src.get_index(i);
    }
    _cnt=src._cnt;
}
template <typename value>
void heap<value>::insert(const reference ref){
    _array[_cnt]=ref;
    int tmp=_cnt;
    while(tmp>0&&cmp(_array[tmp],_array[tmp/2])){
        value tmp_value=_array[tmp];
        _array[tmp]=_array[tmp/2];
        _array[tmp/2]=tmp_value;
        tmp=tmp/2;
    }
    _cnt++;
}
template <typename value>
bool heap<value>::is_empty(){
    if(!_cnt)return true;
    else return false;
}
template <typename value>
value heap<value>::get_most()const{
    return _array[0];
}
template <typename value>
int heap<value>::delete_most(){
    if(_cnt==0){
       cout<<"这是一个空堆"<<std::endl;
       return 0;
    }
    else{
        value tmp=_array[0];
        _array[0]=_array[_cnt-1];
        _array[_cnt-1]=tmp;
        _cnt--;
        int tmp_index=0;
        while(2*tmp_index<_cnt){
            int ltmp_index=2*tmp_index;
            if(ltmp_index+1<_cnt&&cmp(_array[ltmp_index+1],_array[ltmp_index])){
                tmp=_array[ltmp_index+1];
                _array[ltmp_index+1]=_array[tmp_index];
                _array[tmp_index]=tmp;
                tmp_index=ltmp_index+1;
            }
            else if(_array[ltmp_index]>_array[tmp_index]) {
                tmp=_array[ltmp_index];
                _array[ltmp_index]=_array[tmp_index];
                _array[tmp_index]=tmp;
                tmp_index=ltmp_index;
            }
            else break;
        }
    }
}
template <typename value>
int heap<value>::size()const{
    return _cnt;
}
template <typename value>
void heap<value>::translate(value *array,int num,bool(*comp)(const reference,const reference)){
    cmp=comp;
    if(num>_max){
        delete  _array;
        _max=num;
        _array=(pointer)malloc(_max*sizeof(value));
      }
    _cnt=0;
    for(int i=0;i<num;i++){
        insert(array[i]);
    }      
}
template <typename value>
void heap<value>::print(){
    for(int i=0;i<_cnt;i++){
        cout<<_array[i]<<" ";
    }
}
template <typename value>
value heap<value>::get_index(int index)const{
   if(index>=_cnt){
       cout<<"超出当前堆范围"<<std::endl;
   }
   else {
      return _array[index];
   }
}
#endif