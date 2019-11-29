template <typename _type>
class shared_ptr
{
private:
    _type *pointer;
    int ref_num;

public:
    explicit shared_ptr();
    ~shared_ptr();
    _type &operator*()const;  //指针的解引用
    _type *operator->()const; //
    operator bool();
};

