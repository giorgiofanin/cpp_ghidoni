#include <iostream>
#include "myVector2.h"

myVector2::myVector2()
{
    sz = 0;
    bufferSz = 0;
    elem = nullptr;
}

    
myVector2::myVector2(std::initializer_list<double> lst){
    sz = lst.size();
    bufferSz = sz *2;
    elem = new double[bufferSz];

    std::copy(lst.begin(), lst.end(), elem);
}


myVector2::myVector2(int size,double *p)
{
    sz = size;
    bufferSz = sz *2;
    elem = p;

    if (size != 0)
    {
        elem = new double[bufferSz];
        for (int i = 0; i < size; i++)
        {
            elem[i] = p[i];
        }
    }
    else{
        throw myVector2::Invalid{};
    }
}

double &myVector2::operator[](int pos)
{
    return elem[pos];
}

double myVector2::operator[](int pos) const
{
    return elem[pos];
}


double& myVector2::at(int pos){
    if(pos<0 || pos>=size()){
        throw myVector2::out_of_range{};
    }
    else{
        return elem[pos];
    }
}


double myVector2::at(int pos) const{
    if(pos<0 || pos>=size()){
        throw myVector2::out_of_range{};
    }
    else{
        return elem[pos];
    }
}

void myVector2::push_back(double value){
    
    if(sz == bufferSz){
        bufferSz*=2;
        double* newElem =  new double[bufferSz];
        std::copy(elem,elem+sz,newElem);
        delete[] elem;
        elem = newElem;
    }
    elem[sz++]= value;
    
}

// myVector2& operator=(const myVector2& a){
//     double* newP =  new double[a.bufferSz*2];
//     std::copy(a.elem,a.elem+a.sz,p);
//     delete[] elem;
//     elem = p;
//     bufferSz = a.bufferSz*2;
//     sz = a.sz;
//     return *this;
// }

void myVector2::reserve(int n){
    if(bufferSz-sz>= n){
        return;
    }
    bufferSz+=n;

    double* newP =  new double[bufferSz];
    //copy

    delete[] elem;
    elem = newP;
}


void myVector2::pop_back(){
    
    if(sz > 0){
        --sz;
    }
    else{
        throw myVector2::Invalid{};
    }
}
