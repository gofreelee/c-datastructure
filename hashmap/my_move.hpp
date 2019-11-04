#ifndef _MY_MOVE_H
#define _MY_MOVE_H
//先声明一个结构体用来把值　左值引用　右值引用　都转化成值
template <typename T>
struct remove_reference {
    typedef T type;
};

template <typename T>
struct remove_reference <T&> {
    typedef T type;
};

template <typename T>
struct remove_reference <T&&>  {
    typedef T type;
};

template <typename T>
inline typename remove_reference<T>::type&& mmove(T&& value)noexcept{
    return static_cast<typename remove_reference<T>::type&&> (value);
}

#endif