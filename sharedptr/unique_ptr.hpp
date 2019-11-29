template <typename _type>
class unique_ptr
{
public:
    _type *_ptr;
    unique_ptr(_type *ptr = nullptr) : _ptr(ptr) {} //构造函数
    template <typename _subtype>
    unique_ptr(unique_ptr<_subtype> &&res);
    unique_ptr &operator=(unique_ptr res_ptr); //=赋值运算符重载
    _type &operator*() const;                  //*运算符重载
    ~unique_ptr();
    _type *release();
    void swap(_type *des);
};
template <typename _type>
_type *unique_ptr<_type>::release()
{
    _type *tmp_ptr = _ptr;
    _ptr = nullptr;
    return tmp_ptr;
}

template <typename _type>
void unique_ptr<_type>::swap(_type *des)
{
    using namespace std;
    std::swap(_ptr, des);
}

template <typename _type>
template <typename _subtype>
unique_ptr<_type>::unique_ptr(unique_ptr<_subtype> &&res)
{
    _ptr = res.release();
}

template <typename _type>
unique_ptr<_type> &unique_ptr<_type>::operator=(unique_ptr<_type> res)
{
    res.swap(_ptr);
    return *_ptr;
}

template <typename _type>
_type &unique_ptr<_type>::operator*() const
{
    return *_ptr;
}

template <typename _type>
unique_ptr<_type>::~unique_ptr()
{
    free(_ptr);
    _ptr = nullptr;
}