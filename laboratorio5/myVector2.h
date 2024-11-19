#ifndef MYVECTOR2_H
#define MYVECTOR2_H

template<typename T>

class myVector2
{

private:
    int sz;
    int bufferSz;
    T *elem;

public:
    class Invalid{};
    class out_of_range{};

    myVector2();
    myVector2(std::initializer_list<double>);
    explicit myVector2(int  = 0, T * p = nullptr);
    myVector2(myVector2&& a);
    myVector2& operator=(myVector2&&);

    int size() const { return sz; }

    

    T &operator[](int pos);
    T operator[](int pos) const;
    T &at(int pos);
    T at(int pos) const;
    void push_back(T value);
    void pop_back();
    void reserve (int n);
    ~myVector2() { delete[] elem; }
};


#endif