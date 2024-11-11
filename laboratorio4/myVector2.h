#ifndef MYVECTOR2_H
#define MYVECTOR2_H
class myVector2
{

private:
    int sz;
    int bufferSz;
    double *elem;

public:
    class Invalid{};
    class out_of_range{};

    myVector2();
    myVector2(std::initializer_list<double>);
    myVector2(int  = 0, double * p = nullptr);

    int size() const { return sz; }


    double &operator[](int pos);
    double operator[](int pos) const;
    double &at(int pos);
    double at(int pos) const;
    void push_back(double value);
    void pop_back();
    void reserve (int n);
    ~myVector2() { delete[] elem; }
};


#endif