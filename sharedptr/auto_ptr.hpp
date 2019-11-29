
/* 这个自动指针通过RAII原则实现了对于指针的自动管理.
以及做到了当一个auto_ptr用另外一个auto_ptr初始化/赋值时,做到了使得原auto_ptr的指针为nullptr

*/
template <typename _type>
class auto_ptr
{

public:
    _type *_ptr;
    auto_ptr();
    ~auto_ptr();
    auto_ptr(auto_ptr &res);
    void swap(auto_ptr &res);
    _type *release();
    _type &operator*() const;
    auto_ptr &operator=(auto_ptr &res);
};

//初始化为null指针
template <typename _type>
auto_ptr<_type>::auto_ptr()
{
    _ptr = nullptr;
}

//
template <typename _type>
auto_ptr<_type>::~auto_ptr()
{
    free(_ptr);
    _ptr = nullptr;
}

template <typename _type>
_type &auto_ptr<_type>::operator*() const
{
    return *_ptr;
}

template <typename _type>
_type *auto_ptr<_type>::release()
{
    _type *tmp_ptr = _ptr;
    _ptr = nullptr;
    return tmp_ptr;
}

template <typename _type>
auto_ptr<_type>::auto_ptr(auto_ptr<_type> &res)
{
    _ptr = res.release();
}

template <typename _type>
void auto_ptr<_type>::swap(auto_ptr<_type> &res)
{
    using namespace std;
    std::swap(_ptr, res._ptr);
}

/* 赋值操作符会比较特殊,一个是res的指针要给自己,自己要把自己原来的指针free掉,然后res的指针要为nullptr
需要保证这些条件,尽量做到只有析构函数里有free
*/
template <typename _type>
auto_ptr<_type> &auto_ptr<_type>::operator=(auto_ptr<_type> &res)
{
    auto_ptr<_type>(res).swap(*this);
    return *_ptr
}
